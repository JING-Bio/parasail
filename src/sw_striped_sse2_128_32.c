/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdint.h>
#include <stdlib.h>

#include <emmintrin.h>

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_sse.h"

#define NEG_INF (INT32_MIN/(int32_t)(2))

static inline __m128i _mm_max_epi32_rpl(__m128i a, __m128i b) {
    __m128i mask = _mm_cmpgt_epi32(a, b);
    a = _mm_and_si128(a, mask);
    b = _mm_andnot_si128(mask, b);
    return _mm_or_si128(a, b);
}

static inline int32_t _mm_extract_epi32_rpl(__m128i a, const int imm) {
    __m128i_32_t A;
    A.m = a;
    return A.v[imm];
}


#ifdef PARASAIL_TABLE
static inline void arr_store_si128(
        int *array,
        __m128i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen)
{
    array[(0*seglen+t)*dlen + d] = (int32_t)_mm_extract_epi32_rpl(vH, 0);
    array[(1*seglen+t)*dlen + d] = (int32_t)_mm_extract_epi32_rpl(vH, 1);
    array[(2*seglen+t)*dlen + d] = (int32_t)_mm_extract_epi32_rpl(vH, 2);
    array[(3*seglen+t)*dlen + d] = (int32_t)_mm_extract_epi32_rpl(vH, 3);
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_table_striped_sse2_128_32
#else
#define FNAME parasail_sw_striped_sse2_128_32
#endif

parasail_result_t* FNAME(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t k = 0;
    int32_t segNum = 0;
    const int32_t n = 24; /* number of amino acids in table */
    const int32_t segWidth = 4; /* number of values in vector unit */
    const int32_t segLen = (s1Len + segWidth - 1) / segWidth;
    __m128i* const restrict vProfile = parasail_memalign___m128i(16, n * segLen);
    __m128i* restrict pvHStore = parasail_memalign___m128i(16, segLen);
    __m128i* restrict pvHLoad =  parasail_memalign___m128i(16, segLen);
    __m128i* const restrict pvE = parasail_memalign___m128i(16, segLen);
    __m128i vGapO = _mm_set1_epi32(open);
    __m128i vGapE = _mm_set1_epi32(gap);
    __m128i vZero = _mm_setzero_si128();
    __m128i vNegInf = _mm_set1_epi32(NEG_INF);
    int32_t score = NEG_INF;
    __m128i vMaxH = vNegInf;
    
#ifdef PARASAIL_TABLE
    parasail_result_t *result = parasail_result_new_table1(segLen*segWidth, s2Len);
#else
    parasail_result_t *result = parasail_result_new();
#endif

    /* Generate query profile.
     * Rearrange query sequence & calculate the weight of match/mismatch.
     * Don't alias. */
    {
        int32_t index = 0;
        for (k=0; k<n; ++k) {
            for (i=0; i<segLen; ++i) {
                __m128i_32_t t;
                j = i;
                for (segNum=0; segNum<segWidth; ++segNum) {
                    t.v[segNum] = j >= s1Len ? 0 : matrix->matrix[matrix->size*k+matrix->mapper[(unsigned char)s1[j]]];
                    j += segLen;
                }
                _mm_store_si128(&vProfile[index], t.m);
                ++index;
            }
        }
    }

    /* initialize H and E */
    {
        int32_t index = 0;
        for (i=0; i<segLen; ++i) {
            __m128i_32_t h;
            __m128i_32_t e;
            for (segNum=0; segNum<segWidth; ++segNum) {
                h.v[segNum] = 0;
                e.v[segNum] = -open;
            }
            _mm_store_si128(&pvHStore[index], h.m);
            _mm_store_si128(&pvE[index], e.m);
            ++index;
        }
    }

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        __m128i vE;
        /* Initialize F value to 0.  Any errors to vH values will be
         * corrected in the Lazy_F loop.  */
        __m128i vF = vZero;

        /* load final segment of pvHStore and shift left by 2 bytes */
        __m128i vH = _mm_slli_si128(pvHStore[segLen - 1], 4);

        /* Correct part of the vProfile */
        const __m128i* vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;

        /* Swap the 2 H buffers. */
        __m128i* pv = pvHLoad;
        pvHLoad = pvHStore;
        pvHStore = pv;

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            vH = _mm_add_epi32(vH, _mm_load_si128(vP + i));
            vE = _mm_load_si128(pvE + i);

            /* Get max from vH, vE and vF. */
            vH = _mm_max_epi32_rpl(vH, vE);
            vH = _mm_max_epi32_rpl(vH, vF);
            vH = _mm_max_epi32_rpl(vH, vZero);
            /* Save vH values. */
            _mm_store_si128(pvHStore + i, vH);
            
#ifdef PARASAIL_TABLE
            arr_store_si128(result->score_table, vH, i, segLen, j, s2Len);
#endif
            vMaxH = _mm_max_epi32_rpl(vH, vMaxH);

            /* Update vE value. */
            vH = _mm_sub_epi32(vH, vGapO);
            vE = _mm_sub_epi32(vE, vGapE);
            vE = _mm_max_epi32_rpl(vE, vH);
            _mm_store_si128(pvE + i, vE);

            /* Update vF value. */
            vF = _mm_sub_epi32(vF, vGapE);
            vF = _mm_max_epi32_rpl(vF, vH);

            /* Load the next vH. */
            vH = _mm_load_si128(pvHLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
            vF = _mm_slli_si128(vF, 4);
            for (i=0; i<segLen; ++i) {
                vH = _mm_load_si128(pvHStore + i);
                vH = _mm_max_epi32_rpl(vH,vF);
                _mm_store_si128(pvHStore + i, vH);
                
#ifdef PARASAIL_TABLE
                arr_store_si128(result->score_table, vH, i, segLen, j, s2Len);
#endif
                vMaxH = _mm_max_epi32_rpl(vH, vMaxH);
                vH = _mm_sub_epi32(vH, vGapO);
                vF = _mm_sub_epi32(vF, vGapE);
                if (! _mm_movemask_epi8(_mm_cmpgt_epi32(vF, vH))) goto end;
                /*vF = _mm_max_epi32_rpl(vF, vH);*/
            }
        }
end:
        {
        }
    }

    /* max in vec */
    for (j=0; j<segWidth; ++j) {
        int32_t value = (int32_t) _mm_extract_epi32_rpl(vMaxH, 3);
        if (value > score) {
            score = value;
        }
        vMaxH = _mm_slli_si128(vMaxH, 4);
    }

    

    result->score = score;

    parasail_free(pvE);
    parasail_free(pvHLoad);
    parasail_free(pvHStore);
    parasail_free(vProfile);

    return result;
}


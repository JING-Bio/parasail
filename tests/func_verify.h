/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#ifndef _PARASAIL_FUNCTION_GROUP_H_
#define _PARASAIL_FUNCTION_GROUP_H_

#include "parasail.h"

typedef struct parasail_function_info {
    parasail_function_t * pointer;
    const char * name;
    const char * alg;
    const char * type;
    const char * isa;
    const char * bits;
    const char * width;
    int lanes;
    char is_table;
    char is_stats;
    char is_ref;
} parasail_function_info_t;

typedef struct parasail_function_group {
    const char * name;
    parasail_function_info_t *fs;
} parasail_function_group_t;


#if HAVE_SSE2
static parasail_function_info_t parasail_nw_sse2_functions[] = {
{parasail_nw,                         "parasail_nw",                         "nw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_nw_scan,                    "parasail_nw_scan",                    "nw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_nw_scan_sse2_128_64,        "parasail_nw_scan_sse2_128_64",        "nw",    "scan", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_nw_scan_sse2_128_32,        "parasail_nw_scan_sse2_128_32",        "nw",    "scan", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_nw_scan_sse2_128_16,        "parasail_nw_scan_sse2_128_16",        "nw",    "scan", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_nw_scan_sse2_128_8,         "parasail_nw_scan_sse2_128_8",         "nw",    "scan", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_nw_striped_sse2_128_64,     "parasail_nw_striped_sse2_128_64",     "nw", "striped", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_nw_striped_sse2_128_32,     "parasail_nw_striped_sse2_128_32",     "nw", "striped", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_nw_striped_sse2_128_16,     "parasail_nw_striped_sse2_128_16",     "nw", "striped", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_nw_striped_sse2_128_8,      "parasail_nw_striped_sse2_128_8",      "nw", "striped", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_nw_diag_sse2_128_64,        "parasail_nw_diag_sse2_128_64",        "nw",    "diag", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_nw_diag_sse2_128_32,        "parasail_nw_diag_sse2_128_32",        "nw",    "diag", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_nw_diag_sse2_128_16,        "parasail_nw_diag_sse2_128_16",        "nw",    "diag", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_nw_diag_sse2_128_8,         "parasail_nw_diag_sse2_128_8",         "nw",    "diag", "sse2",  "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_sse2 = {"parasail_nw_sse2", parasail_nw_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_sse41_functions[] = {
{parasail_nw,                         "parasail_nw",                         "nw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_nw_scan,                    "parasail_nw_scan",                    "nw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_nw_scan_sse41_128_64,       "parasail_nw_scan_sse41_128_64",       "nw",    "scan", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_nw_scan_sse41_128_32,       "parasail_nw_scan_sse41_128_32",       "nw",    "scan", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_nw_scan_sse41_128_16,       "parasail_nw_scan_sse41_128_16",       "nw",    "scan", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_nw_scan_sse41_128_8,        "parasail_nw_scan_sse41_128_8",        "nw",    "scan", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_nw_striped_sse41_128_64,    "parasail_nw_striped_sse41_128_64",    "nw", "striped", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_nw_striped_sse41_128_32,    "parasail_nw_striped_sse41_128_32",    "nw", "striped", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_nw_striped_sse41_128_16,    "parasail_nw_striped_sse41_128_16",    "nw", "striped", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_nw_striped_sse41_128_8,     "parasail_nw_striped_sse41_128_8",     "nw", "striped", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_nw_diag_sse41_128_64,       "parasail_nw_diag_sse41_128_64",       "nw",    "diag", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_nw_diag_sse41_128_32,       "parasail_nw_diag_sse41_128_32",       "nw",    "diag", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_nw_diag_sse41_128_16,       "parasail_nw_diag_sse41_128_16",       "nw",    "diag", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_nw_diag_sse41_128_8,        "parasail_nw_diag_sse41_128_8",        "nw",    "diag", "sse41", "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_sse41 = {"parasail_nw_sse41", parasail_nw_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_avx2_functions[] = {
{parasail_nw,                         "parasail_nw",                         "nw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_nw_scan,                    "parasail_nw_scan",                    "nw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_nw_scan_avx2_256_64,        "parasail_nw_scan_avx2_256_64",        "nw",    "scan", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_nw_scan_avx2_256_32,        "parasail_nw_scan_avx2_256_32",        "nw",    "scan", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_nw_scan_avx2_256_16,        "parasail_nw_scan_avx2_256_16",        "nw",    "scan", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_nw_scan_avx2_256_8,         "parasail_nw_scan_avx2_256_8",         "nw",    "scan", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_nw_striped_avx2_256_64,     "parasail_nw_striped_avx2_256_64",     "nw", "striped", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_nw_striped_avx2_256_32,     "parasail_nw_striped_avx2_256_32",     "nw", "striped", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_nw_striped_avx2_256_16,     "parasail_nw_striped_avx2_256_16",     "nw", "striped", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_nw_striped_avx2_256_8,      "parasail_nw_striped_avx2_256_8",      "nw", "striped", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_nw_diag_avx2_256_64,        "parasail_nw_diag_avx2_256_64",        "nw",    "diag", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_nw_diag_avx2_256_32,        "parasail_nw_diag_avx2_256_32",        "nw",    "diag", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_nw_diag_avx2_256_16,        "parasail_nw_diag_avx2_256_16",        "nw",    "diag", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_nw_diag_avx2_256_8,         "parasail_nw_diag_avx2_256_8",         "nw",    "diag", "avx2",  "256",  "8", 32, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_avx2 = {"parasail_nw_avx2", parasail_nw_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_nw_knc_functions[] = {
{parasail_nw,                         "parasail_nw",                         "nw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_nw_scan,                    "parasail_nw_scan",                    "nw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_nw_scan_knc_512_32,         "parasail_nw_scan_knc_512_32",         "nw",    "scan", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_nw_striped_knc_512_32,      "parasail_nw_striped_knc_512_32",      "nw", "striped", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_nw_diag_knc_512_32,         "parasail_nw_diag_knc_512_32",         "nw",    "diag", "knc",   "512", "32", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_knc = {"parasail_nw_knc", parasail_nw_knc_functions};
#endif
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_sse2_functions[] = {
{parasail_sg,                         "parasail_sg",                         "sg",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sg_scan,                    "parasail_sg_scan",                    "sg",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sg_scan_sse2_128_64,        "parasail_sg_scan_sse2_128_64",        "sg",    "scan", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sg_scan_sse2_128_32,        "parasail_sg_scan_sse2_128_32",        "sg",    "scan", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sg_scan_sse2_128_16,        "parasail_sg_scan_sse2_128_16",        "sg",    "scan", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sg_scan_sse2_128_8,         "parasail_sg_scan_sse2_128_8",         "sg",    "scan", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_sg_striped_sse2_128_64,     "parasail_sg_striped_sse2_128_64",     "sg", "striped", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sg_striped_sse2_128_32,     "parasail_sg_striped_sse2_128_32",     "sg", "striped", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sg_striped_sse2_128_16,     "parasail_sg_striped_sse2_128_16",     "sg", "striped", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sg_striped_sse2_128_8,      "parasail_sg_striped_sse2_128_8",      "sg", "striped", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_sg_diag_sse2_128_64,        "parasail_sg_diag_sse2_128_64",        "sg",    "diag", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sg_diag_sse2_128_32,        "parasail_sg_diag_sse2_128_32",        "sg",    "diag", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sg_diag_sse2_128_16,        "parasail_sg_diag_sse2_128_16",        "sg",    "diag", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sg_diag_sse2_128_8,         "parasail_sg_diag_sse2_128_8",         "sg",    "diag", "sse2",  "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_sse2 = {"parasail_sg_sse2", parasail_sg_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_sse41_functions[] = {
{parasail_sg,                         "parasail_sg",                         "sg",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sg_scan,                    "parasail_sg_scan",                    "sg",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sg_scan_sse41_128_64,       "parasail_sg_scan_sse41_128_64",       "sg",    "scan", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sg_scan_sse41_128_32,       "parasail_sg_scan_sse41_128_32",       "sg",    "scan", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sg_scan_sse41_128_16,       "parasail_sg_scan_sse41_128_16",       "sg",    "scan", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sg_scan_sse41_128_8,        "parasail_sg_scan_sse41_128_8",        "sg",    "scan", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_sg_striped_sse41_128_64,    "parasail_sg_striped_sse41_128_64",    "sg", "striped", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sg_striped_sse41_128_32,    "parasail_sg_striped_sse41_128_32",    "sg", "striped", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sg_striped_sse41_128_16,    "parasail_sg_striped_sse41_128_16",    "sg", "striped", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sg_striped_sse41_128_8,     "parasail_sg_striped_sse41_128_8",     "sg", "striped", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_sg_diag_sse41_128_64,       "parasail_sg_diag_sse41_128_64",       "sg",    "diag", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sg_diag_sse41_128_32,       "parasail_sg_diag_sse41_128_32",       "sg",    "diag", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sg_diag_sse41_128_16,       "parasail_sg_diag_sse41_128_16",       "sg",    "diag", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sg_diag_sse41_128_8,        "parasail_sg_diag_sse41_128_8",        "sg",    "diag", "sse41", "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_sse41 = {"parasail_sg_sse41", parasail_sg_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_avx2_functions[] = {
{parasail_sg,                         "parasail_sg",                         "sg",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sg_scan,                    "parasail_sg_scan",                    "sg",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sg_scan_avx2_256_64,        "parasail_sg_scan_avx2_256_64",        "sg",    "scan", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sg_scan_avx2_256_32,        "parasail_sg_scan_avx2_256_32",        "sg",    "scan", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sg_scan_avx2_256_16,        "parasail_sg_scan_avx2_256_16",        "sg",    "scan", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sg_scan_avx2_256_8,         "parasail_sg_scan_avx2_256_8",         "sg",    "scan", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_sg_striped_avx2_256_64,     "parasail_sg_striped_avx2_256_64",     "sg", "striped", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sg_striped_avx2_256_32,     "parasail_sg_striped_avx2_256_32",     "sg", "striped", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sg_striped_avx2_256_16,     "parasail_sg_striped_avx2_256_16",     "sg", "striped", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sg_striped_avx2_256_8,      "parasail_sg_striped_avx2_256_8",      "sg", "striped", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_sg_diag_avx2_256_64,        "parasail_sg_diag_avx2_256_64",        "sg",    "diag", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sg_diag_avx2_256_32,        "parasail_sg_diag_avx2_256_32",        "sg",    "diag", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sg_diag_avx2_256_16,        "parasail_sg_diag_avx2_256_16",        "sg",    "diag", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sg_diag_avx2_256_8,         "parasail_sg_diag_avx2_256_8",         "sg",    "diag", "avx2",  "256",  "8", 32, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_avx2 = {"parasail_sg_avx2", parasail_sg_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sg_knc_functions[] = {
{parasail_sg,                         "parasail_sg",                         "sg",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sg_scan,                    "parasail_sg_scan",                    "sg",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sg_scan_knc_512_32,         "parasail_sg_scan_knc_512_32",         "sg",    "scan", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_sg_striped_knc_512_32,      "parasail_sg_striped_knc_512_32",      "sg", "striped", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_sg_diag_knc_512_32,         "parasail_sg_diag_knc_512_32",         "sg",    "diag", "knc",   "512", "32", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_knc = {"parasail_sg_knc", parasail_sg_knc_functions};
#endif
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_sse2_functions[] = {
{parasail_sw,                         "parasail_sw",                         "sw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sw_scan,                    "parasail_sw_scan",                    "sw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sw_scan_sse2_128_64,        "parasail_sw_scan_sse2_128_64",        "sw",    "scan", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sw_scan_sse2_128_32,        "parasail_sw_scan_sse2_128_32",        "sw",    "scan", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sw_scan_sse2_128_16,        "parasail_sw_scan_sse2_128_16",        "sw",    "scan", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sw_scan_sse2_128_8,         "parasail_sw_scan_sse2_128_8",         "sw",    "scan", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_sw_striped_sse2_128_64,     "parasail_sw_striped_sse2_128_64",     "sw", "striped", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sw_striped_sse2_128_32,     "parasail_sw_striped_sse2_128_32",     "sw", "striped", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sw_striped_sse2_128_16,     "parasail_sw_striped_sse2_128_16",     "sw", "striped", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sw_striped_sse2_128_8,      "parasail_sw_striped_sse2_128_8",      "sw", "striped", "sse2",  "128",  "8", 16, 0, 0, 0},
{parasail_sw_diag_sse2_128_64,        "parasail_sw_diag_sse2_128_64",        "sw",    "diag", "sse2",  "128", "64",  2, 0, 0, 0},
{parasail_sw_diag_sse2_128_32,        "parasail_sw_diag_sse2_128_32",        "sw",    "diag", "sse2",  "128", "32",  4, 0, 0, 0},
{parasail_sw_diag_sse2_128_16,        "parasail_sw_diag_sse2_128_16",        "sw",    "diag", "sse2",  "128", "16",  8, 0, 0, 0},
{parasail_sw_diag_sse2_128_8,         "parasail_sw_diag_sse2_128_8",         "sw",    "diag", "sse2",  "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_sse2 = {"parasail_sw_sse2", parasail_sw_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_sse41_functions[] = {
{parasail_sw,                         "parasail_sw",                         "sw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sw_scan,                    "parasail_sw_scan",                    "sw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sw_scan_sse41_128_64,       "parasail_sw_scan_sse41_128_64",       "sw",    "scan", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sw_scan_sse41_128_32,       "parasail_sw_scan_sse41_128_32",       "sw",    "scan", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sw_scan_sse41_128_16,       "parasail_sw_scan_sse41_128_16",       "sw",    "scan", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sw_scan_sse41_128_8,        "parasail_sw_scan_sse41_128_8",        "sw",    "scan", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_sw_striped_sse41_128_64,    "parasail_sw_striped_sse41_128_64",    "sw", "striped", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sw_striped_sse41_128_32,    "parasail_sw_striped_sse41_128_32",    "sw", "striped", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sw_striped_sse41_128_16,    "parasail_sw_striped_sse41_128_16",    "sw", "striped", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sw_striped_sse41_128_8,     "parasail_sw_striped_sse41_128_8",     "sw", "striped", "sse41", "128",  "8", 16, 0, 0, 0},
{parasail_sw_diag_sse41_128_64,       "parasail_sw_diag_sse41_128_64",       "sw",    "diag", "sse41", "128", "64",  2, 0, 0, 0},
{parasail_sw_diag_sse41_128_32,       "parasail_sw_diag_sse41_128_32",       "sw",    "diag", "sse41", "128", "32",  4, 0, 0, 0},
{parasail_sw_diag_sse41_128_16,       "parasail_sw_diag_sse41_128_16",       "sw",    "diag", "sse41", "128", "16",  8, 0, 0, 0},
{parasail_sw_diag_sse41_128_8,        "parasail_sw_diag_sse41_128_8",        "sw",    "diag", "sse41", "128",  "8", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_sse41 = {"parasail_sw_sse41", parasail_sw_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_avx2_functions[] = {
{parasail_sw,                         "parasail_sw",                         "sw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sw_scan,                    "parasail_sw_scan",                    "sw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sw_scan_avx2_256_64,        "parasail_sw_scan_avx2_256_64",        "sw",    "scan", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sw_scan_avx2_256_32,        "parasail_sw_scan_avx2_256_32",        "sw",    "scan", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sw_scan_avx2_256_16,        "parasail_sw_scan_avx2_256_16",        "sw",    "scan", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sw_scan_avx2_256_8,         "parasail_sw_scan_avx2_256_8",         "sw",    "scan", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_sw_striped_avx2_256_64,     "parasail_sw_striped_avx2_256_64",     "sw", "striped", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sw_striped_avx2_256_32,     "parasail_sw_striped_avx2_256_32",     "sw", "striped", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sw_striped_avx2_256_16,     "parasail_sw_striped_avx2_256_16",     "sw", "striped", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sw_striped_avx2_256_8,      "parasail_sw_striped_avx2_256_8",      "sw", "striped", "avx2",  "256",  "8", 32, 0, 0, 0},
{parasail_sw_diag_avx2_256_64,        "parasail_sw_diag_avx2_256_64",        "sw",    "diag", "avx2",  "256", "64",  4, 0, 0, 0},
{parasail_sw_diag_avx2_256_32,        "parasail_sw_diag_avx2_256_32",        "sw",    "diag", "avx2",  "256", "32",  8, 0, 0, 0},
{parasail_sw_diag_avx2_256_16,        "parasail_sw_diag_avx2_256_16",        "sw",    "diag", "avx2",  "256", "16", 16, 0, 0, 0},
{parasail_sw_diag_avx2_256_8,         "parasail_sw_diag_avx2_256_8",         "sw",    "diag", "avx2",  "256",  "8", 32, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_avx2 = {"parasail_sw_avx2", parasail_sw_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sw_knc_functions[] = {
{parasail_sw,                         "parasail_sw",                         "sw",    "orig", "NA",     "32", "32",  1, 0, 0, 1},
{parasail_sw_scan,                    "parasail_sw_scan",                    "sw",    "scan", "NA",     "32", "32",  1, 0, 0, 0},
{parasail_sw_scan_knc_512_32,         "parasail_sw_scan_knc_512_32",         "sw",    "scan", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_sw_striped_knc_512_32,      "parasail_sw_striped_knc_512_32",      "sw", "striped", "knc",   "512", "32", 16, 0, 0, 0},
{parasail_sw_diag_knc_512_32,         "parasail_sw_diag_knc_512_32",         "sw",    "diag", "knc",   "512", "32", 16, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_knc = {"parasail_sw_knc", parasail_sw_knc_functions};
#endif
#if HAVE_SSE2
static parasail_function_info_t parasail_nw_stats_sse2_functions[] = {
{parasail_nw_stats,                   "parasail_nw_stats",                   "nw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_nw_stats_scan,              "parasail_nw_stats_scan",              "nw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_nw_stats_scan_sse2_128_32,  "parasail_nw_stats_scan_sse2_128_32",  "nw_stats",    "scan", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_scan_sse2_128_16,  "parasail_nw_stats_scan_sse2_128_16",  "nw_stats",    "scan", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_scan_sse2_128_8,   "parasail_nw_stats_scan_sse2_128_8",   "nw_stats",    "scan", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_nw_stats_striped_sse2_128_32, "parasail_nw_stats_striped_sse2_128_32", "nw_stats", "striped", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_striped_sse2_128_16, "parasail_nw_stats_striped_sse2_128_16", "nw_stats", "striped", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_striped_sse2_128_8, "parasail_nw_stats_striped_sse2_128_8", "nw_stats", "striped", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_nw_stats_diag_sse2_128_32,  "parasail_nw_stats_diag_sse2_128_32",  "nw_stats",    "diag", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_diag_sse2_128_16,  "parasail_nw_stats_diag_sse2_128_16",  "nw_stats",    "diag", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_diag_sse2_128_8,   "parasail_nw_stats_diag_sse2_128_8",   "nw_stats",    "diag", "sse2",  "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_sse2 = {"parasail_nw_stats_sse2", parasail_nw_stats_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_stats_sse41_functions[] = {
{parasail_nw_stats,                   "parasail_nw_stats",                   "nw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_nw_stats_scan,              "parasail_nw_stats_scan",              "nw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_nw_stats_scan_sse41_128_32, "parasail_nw_stats_scan_sse41_128_32", "nw_stats",    "scan", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_scan_sse41_128_16, "parasail_nw_stats_scan_sse41_128_16", "nw_stats",    "scan", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_scan_sse41_128_8,  "parasail_nw_stats_scan_sse41_128_8",  "nw_stats",    "scan", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_nw_stats_striped_sse41_128_32, "parasail_nw_stats_striped_sse41_128_32", "nw_stats", "striped", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_striped_sse41_128_16, "parasail_nw_stats_striped_sse41_128_16", "nw_stats", "striped", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_striped_sse41_128_8, "parasail_nw_stats_striped_sse41_128_8", "nw_stats", "striped", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_nw_stats_diag_sse41_128_32, "parasail_nw_stats_diag_sse41_128_32", "nw_stats",    "diag", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_nw_stats_diag_sse41_128_16, "parasail_nw_stats_diag_sse41_128_16", "nw_stats",    "diag", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_nw_stats_diag_sse41_128_8,  "parasail_nw_stats_diag_sse41_128_8",  "nw_stats",    "diag", "sse41", "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_sse41 = {"parasail_nw_stats_sse41", parasail_nw_stats_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_stats_avx2_functions[] = {
{parasail_nw_stats,                   "parasail_nw_stats",                   "nw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_nw_stats_scan,              "parasail_nw_stats_scan",              "nw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_nw_stats_scan_avx2_256_32,  "parasail_nw_stats_scan_avx2_256_32",  "nw_stats",    "scan", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_nw_stats_scan_avx2_256_16,  "parasail_nw_stats_scan_avx2_256_16",  "nw_stats",    "scan", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_nw_stats_scan_avx2_256_8,   "parasail_nw_stats_scan_avx2_256_8",   "nw_stats",    "scan", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_nw_stats_striped_avx2_256_32, "parasail_nw_stats_striped_avx2_256_32", "nw_stats", "striped", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_nw_stats_striped_avx2_256_16, "parasail_nw_stats_striped_avx2_256_16", "nw_stats", "striped", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_nw_stats_striped_avx2_256_8, "parasail_nw_stats_striped_avx2_256_8", "nw_stats", "striped", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_nw_stats_diag_avx2_256_32,  "parasail_nw_stats_diag_avx2_256_32",  "nw_stats",    "diag", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_nw_stats_diag_avx2_256_16,  "parasail_nw_stats_diag_avx2_256_16",  "nw_stats",    "diag", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_nw_stats_diag_avx2_256_8,   "parasail_nw_stats_diag_avx2_256_8",   "nw_stats",    "diag", "avx2",  "256",  "8", 32, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_avx2 = {"parasail_nw_stats_avx2", parasail_nw_stats_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_nw_stats_knc_functions[] = {
{parasail_nw_stats,                   "parasail_nw_stats",                   "nw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_nw_stats_scan,              "parasail_nw_stats_scan",              "nw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_nw_stats_scan_knc_512_32,   "parasail_nw_stats_scan_knc_512_32",   "nw_stats",    "scan", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_nw_stats_striped_knc_512_32, "parasail_nw_stats_striped_knc_512_32", "nw_stats", "striped", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_nw_stats_diag_knc_512_32,   "parasail_nw_stats_diag_knc_512_32",   "nw_stats",    "diag", "knc",   "512", "32", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_knc = {"parasail_nw_stats_knc", parasail_nw_stats_knc_functions};
#endif
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_stats_sse2_functions[] = {
{parasail_sg_stats,                   "parasail_sg_stats",                   "sg_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sg_stats_scan,              "parasail_sg_stats_scan",              "sg_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sg_stats_scan_sse2_128_32,  "parasail_sg_stats_scan_sse2_128_32",  "sg_stats",    "scan", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_scan_sse2_128_16,  "parasail_sg_stats_scan_sse2_128_16",  "sg_stats",    "scan", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_scan_sse2_128_8,   "parasail_sg_stats_scan_sse2_128_8",   "sg_stats",    "scan", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_sg_stats_striped_sse2_128_32, "parasail_sg_stats_striped_sse2_128_32", "sg_stats", "striped", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_striped_sse2_128_16, "parasail_sg_stats_striped_sse2_128_16", "sg_stats", "striped", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_striped_sse2_128_8, "parasail_sg_stats_striped_sse2_128_8", "sg_stats", "striped", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_sg_stats_diag_sse2_128_32,  "parasail_sg_stats_diag_sse2_128_32",  "sg_stats",    "diag", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_diag_sse2_128_16,  "parasail_sg_stats_diag_sse2_128_16",  "sg_stats",    "diag", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_diag_sse2_128_8,   "parasail_sg_stats_diag_sse2_128_8",   "sg_stats",    "diag", "sse2",  "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_sse2 = {"parasail_sg_stats_sse2", parasail_sg_stats_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_stats_sse41_functions[] = {
{parasail_sg_stats,                   "parasail_sg_stats",                   "sg_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sg_stats_scan,              "parasail_sg_stats_scan",              "sg_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sg_stats_scan_sse41_128_32, "parasail_sg_stats_scan_sse41_128_32", "sg_stats",    "scan", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_scan_sse41_128_16, "parasail_sg_stats_scan_sse41_128_16", "sg_stats",    "scan", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_scan_sse41_128_8,  "parasail_sg_stats_scan_sse41_128_8",  "sg_stats",    "scan", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_sg_stats_striped_sse41_128_32, "parasail_sg_stats_striped_sse41_128_32", "sg_stats", "striped", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_striped_sse41_128_16, "parasail_sg_stats_striped_sse41_128_16", "sg_stats", "striped", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_striped_sse41_128_8, "parasail_sg_stats_striped_sse41_128_8", "sg_stats", "striped", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_sg_stats_diag_sse41_128_32, "parasail_sg_stats_diag_sse41_128_32", "sg_stats",    "diag", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sg_stats_diag_sse41_128_16, "parasail_sg_stats_diag_sse41_128_16", "sg_stats",    "diag", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sg_stats_diag_sse41_128_8,  "parasail_sg_stats_diag_sse41_128_8",  "sg_stats",    "diag", "sse41", "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_sse41 = {"parasail_sg_stats_sse41", parasail_sg_stats_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_stats_avx2_functions[] = {
{parasail_sg_stats,                   "parasail_sg_stats",                   "sg_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sg_stats_scan,              "parasail_sg_stats_scan",              "sg_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sg_stats_scan_avx2_256_32,  "parasail_sg_stats_scan_avx2_256_32",  "sg_stats",    "scan", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sg_stats_scan_avx2_256_16,  "parasail_sg_stats_scan_avx2_256_16",  "sg_stats",    "scan", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sg_stats_scan_avx2_256_8,   "parasail_sg_stats_scan_avx2_256_8",   "sg_stats",    "scan", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_sg_stats_striped_avx2_256_32, "parasail_sg_stats_striped_avx2_256_32", "sg_stats", "striped", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sg_stats_striped_avx2_256_16, "parasail_sg_stats_striped_avx2_256_16", "sg_stats", "striped", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sg_stats_striped_avx2_256_8, "parasail_sg_stats_striped_avx2_256_8", "sg_stats", "striped", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_sg_stats_diag_avx2_256_32,  "parasail_sg_stats_diag_avx2_256_32",  "sg_stats",    "diag", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sg_stats_diag_avx2_256_16,  "parasail_sg_stats_diag_avx2_256_16",  "sg_stats",    "diag", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sg_stats_diag_avx2_256_8,   "parasail_sg_stats_diag_avx2_256_8",   "sg_stats",    "diag", "avx2",  "256",  "8", 32, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_avx2 = {"parasail_sg_stats_avx2", parasail_sg_stats_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sg_stats_knc_functions[] = {
{parasail_sg_stats,                   "parasail_sg_stats",                   "sg_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sg_stats_scan,              "parasail_sg_stats_scan",              "sg_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sg_stats_scan_knc_512_32,   "parasail_sg_stats_scan_knc_512_32",   "sg_stats",    "scan", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_sg_stats_striped_knc_512_32, "parasail_sg_stats_striped_knc_512_32", "sg_stats", "striped", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_sg_stats_diag_knc_512_32,   "parasail_sg_stats_diag_knc_512_32",   "sg_stats",    "diag", "knc",   "512", "32", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_knc = {"parasail_sg_stats_knc", parasail_sg_stats_knc_functions};
#endif
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_stats_sse2_functions[] = {
{parasail_sw_stats,                   "parasail_sw_stats",                   "sw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sw_stats_scan,              "parasail_sw_stats_scan",              "sw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sw_stats_scan_sse2_128_32,  "parasail_sw_stats_scan_sse2_128_32",  "sw_stats",    "scan", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_scan_sse2_128_16,  "parasail_sw_stats_scan_sse2_128_16",  "sw_stats",    "scan", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_scan_sse2_128_8,   "parasail_sw_stats_scan_sse2_128_8",   "sw_stats",    "scan", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_sw_stats_striped_sse2_128_32, "parasail_sw_stats_striped_sse2_128_32", "sw_stats", "striped", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_striped_sse2_128_16, "parasail_sw_stats_striped_sse2_128_16", "sw_stats", "striped", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_striped_sse2_128_8, "parasail_sw_stats_striped_sse2_128_8", "sw_stats", "striped", "sse2",  "128",  "8", 16, 0, 1, 0},
{parasail_sw_stats_diag_sse2_128_32,  "parasail_sw_stats_diag_sse2_128_32",  "sw_stats",    "diag", "sse2",  "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_diag_sse2_128_16,  "parasail_sw_stats_diag_sse2_128_16",  "sw_stats",    "diag", "sse2",  "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_diag_sse2_128_8,   "parasail_sw_stats_diag_sse2_128_8",   "sw_stats",    "diag", "sse2",  "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_sse2 = {"parasail_sw_stats_sse2", parasail_sw_stats_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_stats_sse41_functions[] = {
{parasail_sw_stats,                   "parasail_sw_stats",                   "sw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sw_stats_scan,              "parasail_sw_stats_scan",              "sw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sw_stats_scan_sse41_128_32, "parasail_sw_stats_scan_sse41_128_32", "sw_stats",    "scan", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_scan_sse41_128_16, "parasail_sw_stats_scan_sse41_128_16", "sw_stats",    "scan", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_scan_sse41_128_8,  "parasail_sw_stats_scan_sse41_128_8",  "sw_stats",    "scan", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_sw_stats_striped_sse41_128_32, "parasail_sw_stats_striped_sse41_128_32", "sw_stats", "striped", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_striped_sse41_128_16, "parasail_sw_stats_striped_sse41_128_16", "sw_stats", "striped", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_striped_sse41_128_8, "parasail_sw_stats_striped_sse41_128_8", "sw_stats", "striped", "sse41", "128",  "8", 16, 0, 1, 0},
{parasail_sw_stats_diag_sse41_128_32, "parasail_sw_stats_diag_sse41_128_32", "sw_stats",    "diag", "sse41", "128", "32",  4, 0, 1, 0},
{parasail_sw_stats_diag_sse41_128_16, "parasail_sw_stats_diag_sse41_128_16", "sw_stats",    "diag", "sse41", "128", "16",  8, 0, 1, 0},
{parasail_sw_stats_diag_sse41_128_8,  "parasail_sw_stats_diag_sse41_128_8",  "sw_stats",    "diag", "sse41", "128",  "8", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_sse41 = {"parasail_sw_stats_sse41", parasail_sw_stats_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_stats_avx2_functions[] = {
{parasail_sw_stats,                   "parasail_sw_stats",                   "sw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sw_stats_scan,              "parasail_sw_stats_scan",              "sw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sw_stats_scan_avx2_256_32,  "parasail_sw_stats_scan_avx2_256_32",  "sw_stats",    "scan", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sw_stats_scan_avx2_256_16,  "parasail_sw_stats_scan_avx2_256_16",  "sw_stats",    "scan", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sw_stats_scan_avx2_256_8,   "parasail_sw_stats_scan_avx2_256_8",   "sw_stats",    "scan", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_sw_stats_striped_avx2_256_32, "parasail_sw_stats_striped_avx2_256_32", "sw_stats", "striped", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sw_stats_striped_avx2_256_16, "parasail_sw_stats_striped_avx2_256_16", "sw_stats", "striped", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sw_stats_striped_avx2_256_8, "parasail_sw_stats_striped_avx2_256_8", "sw_stats", "striped", "avx2",  "256",  "8", 32, 0, 1, 0},
{parasail_sw_stats_diag_avx2_256_32,  "parasail_sw_stats_diag_avx2_256_32",  "sw_stats",    "diag", "avx2",  "256", "32",  8, 0, 1, 0},
{parasail_sw_stats_diag_avx2_256_16,  "parasail_sw_stats_diag_avx2_256_16",  "sw_stats",    "diag", "avx2",  "256", "16", 16, 0, 1, 0},
{parasail_sw_stats_diag_avx2_256_8,   "parasail_sw_stats_diag_avx2_256_8",   "sw_stats",    "diag", "avx2",  "256",  "8", 32, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_avx2 = {"parasail_sw_stats_avx2", parasail_sw_stats_avx2_functions};
#endif
#if HAVE_KNC
static parasail_function_info_t parasail_sw_stats_knc_functions[] = {
{parasail_sw_stats,                   "parasail_sw_stats",                   "sw_stats",    "orig", "NA",     "32", "32",  1, 0, 1, 1},
{parasail_sw_stats_scan,              "parasail_sw_stats_scan",              "sw_stats",    "scan", "NA",     "32", "32",  1, 0, 1, 0},
{parasail_sw_stats_scan_knc_512_32,   "parasail_sw_stats_scan_knc_512_32",   "sw_stats",    "scan", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_sw_stats_striped_knc_512_32, "parasail_sw_stats_striped_knc_512_32", "sw_stats", "striped", "knc",   "512", "32", 16, 0, 1, 0},
{parasail_sw_stats_diag_knc_512_32,   "parasail_sw_stats_diag_knc_512_32",   "sw_stats",    "diag", "knc",   "512", "32", 16, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_knc = {"parasail_sw_stats_knc", parasail_sw_stats_knc_functions};
#endif

#endif /* _PARASAIL_FUNCTION_GROUP_H_ */


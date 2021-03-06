/*
 * File: l1d.h
 * Project: l1d
 * Created Date: Wednesday November 4th 2020
 * Author: Ronan (ronan.lashermes@inria.fr)
 * -----
 * Last Modified: Friday, 20th August 2021 10:48:27 am
 * Modified By: Ronan (ronan.lashermes@inria.fr>)
 * -----
 * Copyright (c) 2020 INRIA
 */

#ifndef L1D_H
#define L1D_H

#include "support.h"

// requires
// - D_SETS
// - D_WAYS
// - D_LINE_SIZE
// - I_LINE_SIZE

#define L1D_WORD_COUNT (L1D_SIZE/sizeof(WORD))

// A structure of the size of L1D
typedef volatile struct {
    WORD words[L1D_WORD_COUNT];
} __attribute__ ((aligned (D_LINE_SIZE)))
l1d_work_area;


volatile inline WORD touch_l1d_add(ADDRESS address);
volatile TIMECOUNT poke_l1d_add(ADDRESS address);// __attribute__((always_inline));

#endif

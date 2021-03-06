/*
 * File: chipsupport.h
 * Project: generic
 * Created Date: Wednesday November 4th 2020
 * Author: Ronan (ronan.lashermes@inria.fr)
 * -----
 * Last Modified: Wednesday, 26th May 2021 3:02:30 pm
 * Modified By: Ronan (ronan.lashermes@inria.fr>)
 * -----
 * Copyright (c) 2020 INRIA
 */

#ifndef CHIP_SUPPORT_H
#define CHIP_SUPPORT_H

#include "../../armv8a.h"


// L1D dimensions
//l1d assumes RAM size >= 2*L1D size
#define D_WAYS 4
#define D_SETS 64
#define D_LINE_SIZE 64
#define L1D_SIZE (D_LINE_SIZE * D_WAYS * D_SETS) //16kB

// L1I dimensions
#define I_WAYS 4
#define I_SETS 64
#define I_LINE_SIZE 64
#define L1I_SIZE (I_LINE_SIZE * I_WAYS * I_SETS) //16kB

// BHT dimensions
#define BHT_ENTRIES 128
#define BHT_COUNTER_BITS    2 //to evaluate the number of passes for training

// BTB dimensions
#define BTB_ENTRIES 32


#endif
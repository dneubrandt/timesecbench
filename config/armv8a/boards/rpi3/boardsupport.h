/*
 * File: boardsupport.h
 * Project: generic
 * Created Date: Wednesday November 4th 2020
 * Author: Ronan (ronan.lashermes@inria.fr)
 * -----
 * Last Modified: Friday, 6th November 2020 10:36:23 am
 * Modified By: Ronan (ronan.lashermes@inria.fr>)
 * -----
 * Copyright (c) 2020 INRIA
 */

#ifndef BOARDSUPPORT_H
#define BOARDSUPPORT_H
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#define CPU_MHZ 1
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;




volatile inline uint32_t read_time() 
{
    uint64_t r;
    /* Access cycle counter */
    asm volatile("mrs %0, pmccntr_el0" : "=r" (r));

    return (uint32_t)(r & 0xFFFFFFFF);
}


#endif
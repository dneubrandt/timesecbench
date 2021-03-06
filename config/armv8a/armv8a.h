/*
 * File: armv8a.h
 * Project: riscv32
 * Created Date: Wednesday November 25th 2020
 * Author: Ronan (ronan.lashermes@inria.fr)
 * -----
 * Last Modified: Friday, 11th June 2021 9:35:51 am
 * Modified By: Ronan (ronan.lashermes@inria.fr>)
 * -----
 * Copyright (c) 2020 INRIA
 */

#ifndef ARMV8A_H
#define ARMV8A_H


typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef void volatile* ADDRESS;
typedef uint64_t TIMECOUNT;
typedef uint64_t WORD;
typedef uint32_t INST;


#define RET_OPCODE      0xd65f03c0  // opcode for "ret"
#define BLT01_OPCODE    0x5400000B    // opcode for "blt a0, a1, 0"
#define J_OPCODE        0x04000000        // opcode for "j 0" (direct jump)
//000x 01ii iiii iiii iiii iiii iiii iiii  -  b ADDR_PCREL26

unsigned int encode_branch_offset(unsigned int offset);

unsigned int encode_jump_offset(unsigned int offset);


#endif
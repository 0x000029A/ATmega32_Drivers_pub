/************************************
 0   File Name: LIB_VRT_STD_TYPES.h 0
 x   File Type: Library             x
 2       Layer: Vertical            2
 A  Created on: Aug 31, 2021        A
 *      Author: Mahmoud Hashem      *
 * Description: Standard data types *
 *     Version: v1.0                *
 ************************************/

/* Header file guard */
#ifndef LIB_VRT_STD_TYPES_H_
#define LIB_VRT_STD_TYPES_H_

/* Defining Standard data types */

typedef unsigned char       u8;     // 1 byte  unsigned char     variable %c
typedef signed  char        s8;     // 1 byte  signed   char     variable %c

typedef unsigned short      u16;    // 2 bytes unsigned integer  variable %hu
typedef signed short        s16;    // 2 bytes signed   integer  variable %hd

typedef unsigned long       u32;    // 4 bytes unsigned integer  variable %lu
typedef signed long         s32;    // 4 bytes signed   integer  variable %ld

typedef unsigned long long  u64;    // 8 bytes unsigned integer  variable %llu
typedef signed long long    s64;    // 8 bytes signed   integer  variable %lld

typedef float               f32;    // 4 bytes signed   floating variable %f
typedef double              f64;    // 8 bytes signed   floating variable %lf

#define VALID               1
#define ERROR               0

#define NULL                0

#define IDLE_FUN            1
#define BUSY_FUN            0

#endif /* LIB_VRT_STD_TYPES_H_ */

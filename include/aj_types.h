
#ifndef __TYPES_H__
#define __TYPES_H__


typedef unsigned long        uint32_t;
typedef unsigned long long   uint64_t;

typedef    _Bool  bool;

#define false 0
#define true  1

typedef unsigned long long size_t;

#define SIZE_MAX		(9223372036854775807UL)

#define NULL ((void *)0)

#define MIN(a, b)		((a) < (b) ? (a) : (b))
#define MAX(a, b)		((a) > (b) ? (a) : (b))

#endif
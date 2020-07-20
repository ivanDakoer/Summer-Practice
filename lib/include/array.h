#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "requires.h"


typedef union
{
    int Int;
    float Float;
} DATA;

typedef union 
{
    int *Int;
    float *Float;
} POINTER;

typedef struct
{
    double min, max;
} RANGE;

typedef enum
{
    _int_,
    _float_
} TYPE;

typedef struct
{
    POINTER Elements;
    DATA Min, Max;

    TYPE Type;
    
    int Length;
} Array;


void CreateArray(Array *array, int lengthArray, TYPE type);

void FillArray(Array *array, RANGE range);

void PrintArray(Array array);

void SortArray(Array *array, int first, int last);

#endif
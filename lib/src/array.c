#include "array.h"

void CreateArray(Array *array, int lengthArray, TYPE type)
{
    array->Length = lengthArray;

    switch (type)
    {
        case _float_: 
        {
            array->Elements.Float = (float *) malloc(lengthArray * _FLOAT_);
            array->Type = _float_;
            break;
        }

        default:
        {
            array->Elements.Int = (int *) malloc(lengthArray * _INT_);
            array->Type = _int_;
            break;
        }
    }

    if (array->Elements.Int == NULL) exit(EXIT_FAILURE);
}

static void FindMaxAndMin(Array *array) 
{
    switch (array->Type) 
    {
        case _float_:
        {
            array->Min.Float = array->Max.Float = array->Elements.Float[0];

            for (int i = 1; i < array->Length; ++i)
            {
               if (array->Min.Float > array->Elements.Float[i])
                {
                    array->Min.Float = array->Elements.Float[i];
                }
                if (array->Max.Float < array->Elements.Float[i])
                {
                    array->Max.Float = array->Elements.Float[i];
                }
            }
            break;
        }

        default:
        {
            array->Min.Int = array->Max.Int = array->Elements.Int[0];

            for (int i = 1; i < array->Length; ++i)
            {
                if (array->Min.Int > array->Elements.Int[i])
                {
                    array->Min.Int = array->Elements.Int[i];
                }
                if (array->Max.Int < array->Elements.Int[i])
                {
                    array->Max.Int = array->Elements.Int[i];
                }
            }
            break;
        }
    }
}

void FillArray(Array *array, RANGE range) 
{
    switch (array->Type) 
    {
        case _float_:
        {
            for (int i = 0; i < array->Length; ++i)
            {
                array->Elements.Float[i] = random(range.min, range.max);
            }
            break;
        }

        default:
        {
            for (int i = 0; i < array->Length; ++i)
            {
                array->Elements.Int[i] = random(range.min, range.max);
            }
            break;
        }
    }

    FindMaxAndMin(array);
}

void PrintArray(Array array)
{
    switch (array.Type)
    {
        case _float_:
        {
            for (int i = 0; i < array.Length; ++i)
            {
                printf("%6.2f ", array.Elements.Float[i]);
            }
            printf("\n");
            break;
        }

        default:
        {
            for (int i = 0; i < array.Length; ++i)
            {
                printf("%6d ", array.Elements.Int[i]);
            }
            printf("\n");
            break;
        }
    }
}

void SortArray(Array *array, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last;
        int middle;
        if (array->Type == _float_)
        {
            middle = array->Elements.Float[(left + right) / 2];
        }
        else
        {
            middle = array->Elements.Int[(left + right) / 2];
        }
        
        do
        {
            if (array->Type == _float_)
            {
                while (array->Elements.Float[left] < middle) left++;
                while (array->Elements.Float[right] > middle) right--;
                if (left <= right)
                {
                    int tmp = array->Elements.Float[left];
                    array->Elements.Float[left] = array->Elements.Float[right];
                    array->Elements.Float[right] = tmp;
                    left++;
                    right--;
                }
            }
            else
            {
                while (array->Elements.Int[left] < middle) left++;
                while (array->Elements.Int[right] > middle) right--;
                if (left <= right)
                {
                    int tmp = array->Elements.Int[left];
                    array->Elements.Int[left] = array->Elements.Int[right];
                    array->Elements.Int[right] = tmp;
                    left++;
                    right--;
                }
            }
        } while (left <= right);
        SortArray(array, first, right);
        SortArray(array, left, last);
    }

    FindMaxAndMin(array);
}
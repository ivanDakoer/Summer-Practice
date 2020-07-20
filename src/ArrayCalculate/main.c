#include "array.h"

int main() {
    RANGE btw = { .min = 1, .max = 99 };
    Array T;

    CreateArray(&T, 11, _int_);
    FillArray(&T, btw);
    
    PrintArray(T);
    printf("min = %d, max = %d, avg = %.2f\n", 
        T.Min.Int, T.Max.Int, (float)(T.Min.Int + T.Max.Int) / 2);

    return EXIT_SUCCESS;
}
#include "array.h"

int main()
{
    RANGE btw = {.min = -10, .max = 10};
    Array B;

    CreateArray(&B, 11, _int_);
    FillArray(&B, btw);

    PrintArray(B);
    printf("Max = %d\n", B.Max.Int);

    SortArray(&B, 0, B.Length - 1);

    for (int i = 0; i < B.Length; ++i)
    {
        B.Elements.Int[i] -= B.Max.Int;
    }

    PrintArray(B);

    return EXIT_SUCCESS;
}
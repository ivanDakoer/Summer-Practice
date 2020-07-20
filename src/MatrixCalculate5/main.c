#include "matrix.h"

#define MIN_VALUE -10
#define MAX_VALUE  10

int main()
{
    int N, **A;

    printf("N = ");
    scanf("%d", &N);

    A = Matrix(N, N);

    srand(time(NULL));

    fillMatrix(N, N, A, (int []){MIN_VALUE, MAX_VALUE});

    printMatrix(N, N, A);

    int *arr = (int *) malloc(N * _INT_);
    if (arr == NULL) return EXIT_FAILURE;

    for (int i = 0; i < N; i++)
    {
        int index = 0;
        int min = **(A + i * N);
        for (int j = 0; j < N; j++)
        {
            if (min > **(A + i * N + j)) {
                min = **(A + i * N + j);
                index = j;
            }
        }

        arr[i] = index;
    }

    for (int i = 0; i < N; i++, printf("%6d ", arr[i]));


    free(arr);
    freeMatrix(N, A);

    return EXIT_SUCCESS;
}
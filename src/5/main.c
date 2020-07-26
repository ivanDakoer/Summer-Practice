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

    int *arr = (int *) calloc(N, _INT_);
    if (arr == NULL) return EXIT_FAILURE;

    for (int i = 0; i < N; i++)
    {
        int index = 0;
        int min = *A[i];
        for (int j = 0; j < N; j++)
        {
            if (min > *(A[i] + j)) {
                min = *(A[i] + j);
                index = j;
            }
        }
        arr[i] = index;
    }

    for (int i = 0; i < N; printf("%6d ", arr[i]), i++);


    free(arr);
    freeMatrix(N, A);

    return EXIT_SUCCESS;
}
#include "matrix.h"

int main()
{
    int **A;
    int N;

    printf("N = ");
    scanf("%d", &N);

    A = Matrix(N, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = (i + j) % 2;
        }
    }

    printMatrix(N, N, A);

    freeMatrix(N, A);

    return EXIT_SUCCESS;
}
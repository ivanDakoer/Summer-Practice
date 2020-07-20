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
            if (i % 2 == 1) A[i][j] = (j % 2 == 1) ? 0 : 1;
            else A[i][j] = (j % 2 == 1) ? 0 : 1;
        }
    }

    freeMatrix(N, A);

    return EXIT_SUCCESS;
}
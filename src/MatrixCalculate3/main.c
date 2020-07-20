#include "matrix.h"

#define N 5

#define MIN_VALUE -10
#define MAX_VALUE  10

int main()
{
    int **V = Matrix(N, N);
    int vector[N];

    srand(time(NULL));

    fillMatrix(N, N, V, (int []){MIN_VALUE, MAX_VALUE});

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            vector[i] = V[i][j];
        }
    }

    for (int i = 0; i < N; i++, printf("%6d ", vector[i]));

    freeMatrix(N, V);

    return EXIT_SUCCESS;
}
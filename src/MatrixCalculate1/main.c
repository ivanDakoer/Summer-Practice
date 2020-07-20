#include "matrix.h"

#define ROWS    5
#define COLUMNS 4

#define MIN_VALUE   -10
#define MAX_VALUE    10

int main()
{
    int **L = Matrix(ROWS, COLUMNS);
    int min, max;

    srand(time(NULL));

    fillMatrix(ROWS, COLUMNS, L, (int[]){MIN_VALUE, MAX_VALUE});
    printMatrix(ROWS, COLUMNS, L);

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            min = min > L[i][j] ? L[i][j] : min;
            max = max < L[i][j] ? L[i][j] : max;
        }
    }

    printf("min = %d, max = %d, avg = %.2f", min, max, (min + max) / 2);

    freeMatrix(ROWS, L);

    return EXIT_SUCCESS;
}
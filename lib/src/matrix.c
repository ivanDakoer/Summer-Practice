#include "matrix.h"

int **Matrix(int rows, int clmns)
{
    int **matrix;
    
    if ((matrix = (int **) malloc(rows * _P_INT_)) == NULL)
    {
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = (int *) malloc(clmns * _INT_);
        if (matrix[i] == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

void fillMatrix(int rows, int clmns, int **matrix, int range[2])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < clmns; ++j)
        {
            matrix[i][j] = random(range[0], range[1]);
        }
    }
}

void printMatrix(int rows, int clmns, int **matrix)
{
    for (int i = 0; i < rows; ++i, printf("\n"))
    {
        for (int j = 0; j < clmns; ++j)
        {
            printf("%6d ", matrix[i][j]);
        }
    }

    printf("\n");
}

void freeMatrix(int rows, int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}
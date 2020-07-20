#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "requires.h"

int **Matrix(int rows, int clmns);

void fillMatrix(int rows, int clmns, int **matrix, int range[2]);

void printMatrix(int rows, int clmns, int **matrix);

void freeMatrix(int rows, int **matrix);

#endif
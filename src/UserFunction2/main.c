#include "requires.h"

typedef struct { float value; struct { int i, j; } index;  } index;

int main()
{
    const int n = random(1, 4);
    const int m = random(1, 4);

    float **A = (float **) malloc(m * _P_FLOAT_);
    if (A == NULL) return EXIT_FAILURE;
    for (int i = 0; i < n; ++i) 
    {
        A[i] = (float *) malloc(n * _FLOAT_);
        if (A[i] == NULL) return EXIT_FAILURE;
    }

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = 2*m + 16 * random(0, n);
        }
    }

    float product = 1;
    index min = { .value = A[0][0], .index = {0, 0} };

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((A[i][j] < -5) || (A[i][j] > 3)) product *= A[i][j];
            if (min.value > A[i][j])
            {
                min.value = A[i][j];
                min.index.i = i;
                min.index.j = j;
            }
        }
    }

    printf("product = %.3f, min = {%.3f {%d, %d}}", product, min.value, min.index.i, min.index.j);

    return 0;
}
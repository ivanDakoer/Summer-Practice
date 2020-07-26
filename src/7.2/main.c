#include "requires.h"

int main()
{
    srand(time(NULL));

    const int n = random(2, 4);
    const int m = random(2, 4);

    float **A = (float **) malloc(m * _P_FLOAT_);
    if (A == NULL) return EXIT_FAILURE;
    for (int i = 0; i < m; i++) 
    {
        A[i] = (float *) malloc(n * _FLOAT_);
        if (A[i] == NULL) return EXIT_FAILURE;
    }


    for (int i = 0; i < m; i++, printf("\n")) 
    {
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = random(-15, 15);
	    printf("%6.2f ", A[i][j]);
        }
    }

    float product = 1;
    float min = A[0][0];
    int minI = 0, minJ = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((A[i][j] < -5.0) || (A[i][j] > 3.0)) product *= A[i][j];
            if (min > A[i][j])
            {
                min = A[i][j];
                minI = i;
                minJ = j;
            }
        }
    }

    for (int i = 0; i < m; i++) free(A[i]);
    free(A);    

    printf("product = %.2f, min = %.2f, index = (%d, %d)", 
	    product, min, minI, minJ);


    return 0;
}
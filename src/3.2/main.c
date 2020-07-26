#include "matrix.h"

#define N 4

#define MIN_VALUE 1
#define MAX_VALUE 100

int main()
{
    int **RR = Matrix(N, N);

    srand(time(NULL));

    fillMatrix(N, N, RR, (int[]){MIN_VALUE, MAX_VALUE});
    printMatrix(N, N, RR);

    float minAvg = 0;
    for (int j = 0; j < N; ++j) minAvg += RR[0][j];
    minAvg = (float)minAvg / N;

    int index = 0;
    for (int i = 1; i < N; ++i)
    {
        float tmpAvg = 0;
        for (int j = 0; j < N; ++j)
        {
            tmpAvg += RR[i][j];
        }
        tmpAvg = (float)tmpAvg / N;
        
        if (minAvg > tmpAvg)
        {
            minAvg = tmpAvg;
            index = i;
        }
    }

    printf("minAvg = %.2f, index = %d", minAvg, index);

    freeMatrix(N, RR);

    return EXIT_SUCCESS;
}
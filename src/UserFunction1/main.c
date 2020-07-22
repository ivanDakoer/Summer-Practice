#include "requires.h"

#define N 10

float *F(int lenArr)
{
    float *arr = (float *) malloc(lenArr * _FLOAT_);
    if (arr == NULL) return NULL;

    for (int i = 0; i < lenArr; i++)
    {
        arr[i] = random(1, 15);
    }
}

int isNegativeFloat(float num) { return num < 0; }

int main()
{
    const int n = 12;
    float *y = F(n);
    int negCount = 0, posCount = 0;
    float negAvg = 0;

    for (int i = 0; i < n; i++)
    {
        if (isNegativeFloat(y[i]) == 0)
        {
            negCount++;
            negAvg += y[i];
            continue;
        }
        posCount++;
    }

    negAvg /= negCount;

    printf("neg = %d, pos = %d, avg = %.3f", negCount, posCount, negAvg);

    return 0;
}
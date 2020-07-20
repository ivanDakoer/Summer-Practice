#include "matrix.h"

#define K 6
#define N 5

typedef struct { int village, candidate; } vote;

int main() {

    int A[K][N];

    srand(time(NULL));

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = random(0, 10 * i + 50);
        }
    }

    for (int i = 0; i < K; i++, printf("\n"))
    {
        for (int j = 0; j < N; j++)
        {
            printf("%6d ", A[i][j]);
        }
    }

    int p;
    printf("p = ");
    scanf("%p", &p);

    int topRate = p;

    vote v = {0, 0};

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] > topRate)
            {
                topRate = A[i][j];
                v.village = i;
                v.candidate = j;
            }
        }
    }

    if (v.candidate == 0 && v.village == 0)
    {
        printf("Doesn't exist!");
        return EXIT_SUCCESS;
    }
    
    printf("(%d, %d)", v.village, v.candidate);

    return EXIT_SUCCESS;
}
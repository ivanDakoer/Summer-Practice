#include "matrix.h"

#define K 6
#define N 5

int main() {

    int A[K][N];

    srand(time(NULL));

    for (int i = 0; i < K; i++, printf("\n"))
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = random(0, 10 * i + 50);
	    printf("%6d ", A[i][j]);
        }
    }

    int p;
    printf("p = ");
    scanf("%d", &p);

    int topRate = A[0][0];

    int indexI = -1, indexJ = -1;

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] > p)
            {
                topRate = A[i][j];
                indexI = i;
                indexJ = j;
            }
        }
    }
   
    if (indexI == -1 && indexJ == -1)
    {
        printf("Doesn't exist.\n");
        return EXIT_SUCCESS;
    } 
    printf("(%d, %d)", indexI, indexJ);

    return EXIT_SUCCESS;
}
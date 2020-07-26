#include "requires.h"

double sumr(int n) { return (n == 0) ? 1 : 1.0 / (1 + n) + sumr(n - 1); }

int main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    printf("%lf", sumr(n));
    return EXIT_SUCCESS;
}
#include "requires.h"

double sumr(int n) { return (n == 0) ? 1 : 1.0 / (1 + n) + sumr(n - 1); }

int main()
{
    printf("%lf", sumr(3));
    return EXIT_SUCCESS;
}
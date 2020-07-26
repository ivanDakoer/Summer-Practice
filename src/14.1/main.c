#include "requires.h"

int main()
{
    char S[BUFSIZ];
    char S0[BUFSIZ];

    printf("Enter S: ");
    fflush(stdin);
    fgets(S, BUFSIZ, stdin);

    printf("Enter S0: ");
    fflush(stdin);
    fgets(S0, BUFSIZ, stdin);

    S[strlen(S) - 1] = '\0';
    S0[strlen(S0) - 1] = '\0';

    if (strlen(S0) > strlen(S))
    {
        printf("S0 is bigger than S");
        return EXIT_FAILURE;
    }

    int count = 0;

    for (char *p = S; p = strstr(p, S0); p++, count++);
    
    printf("%s - %d", S0, count);

    return EXIT_SUCCESS;
}
#include "requires.h"

int main()
{
    char str[BUFSIZ];
    int count = 0;


    fgets(str, sizeof str, stdin);

    for (char *pchr = str; *pchr; pchr++)
    {
       if (*pchr == 'a') count++;
    }

    printf("count of a = %d\n", count);

    char *pch = strtok(str, " ");
    while (pch != NULL)
    {
        printf("\n%d", strlen(pch));
        pch = strtok(NULL, " ");
    }

    return EXIT_SUCCESS;
}
#include "requires.h"

int main()
{
    char tmp[BUFSIZ];
    
    fgets(tmp, sizeof tmp, stdin);

    char *str = (char *) malloc(sizeof tmp + 1);

    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 || str[i - 1] == ' ')
            str[i] = toupper(str[i]);
    }

    return EXIT_SUCCESS;
}
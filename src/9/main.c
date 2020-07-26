#include "requires.h"

void upWords(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ((i == 0) || (str[i - 1] == ' '))
            str[i] = toupper(str[i]);
    }
}

int main()
{
    char tmp[BUFSIZ];
    
    fgets(tmp, sizeof tmp, stdin);

    char *str = (char *) malloc(sizeof tmp + 1);
    if (str == NULL) return EXIT_FAILURE;
    strcpy(str, tmp);


    printf("%s\n", str);
    upWords(str);
    printf("%s\n", str);

    return EXIT_SUCCESS;
}

#include "mystring.h"

void strlenWords(char *str)
{
    char *pch = strtok(str, " ");
    while (pch != NULL)
    {
        printf("\n%d", strlen(pch));
        pch = strtok(NULL, " ");
    }
}

void strlenWords_s(const char *str)
{
    for (int i = 0, len = 0; i < strlen(str); i++, len++)
    {
        if ((i == 0) || (str[i - 1] == ' ')) 
        {
            len = 0;
        }
        if ((str[i] == ' ') || (i == strlen(str) - 1))
        {
            printf("%d ", len);
        }
    }
}

int countSymbol(const char *str, const char c)
{
    int count = 0;
    for (const char *pchr = str; *pchr; pchr++)
    {
        if (*pchr == c)
            count++;
    }

    return count;
}

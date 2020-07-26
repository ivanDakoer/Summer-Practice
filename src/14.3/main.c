#include "requires.h"

#define MAX 100

int startsWith(const char *string, const char *start)
{
    int len = strlen(string) - strlen(start);
    return (len < 0) ? 0 : strncmp(string, start, strlen(start)) == 0;
}

int main()
{
    const char *prefix[] = { "re", "not", "be" }, *del = " \r\t";
    char line[256], *word, *words[MAX];
    size_t len, count;

    count = 0;
    do
    {
        printf("Enter string or press enter to end:");
        fflush(stdin);
        fgets(line, 256, stdin);
        word = strtok(line, del);
        while (word != NULL)
        {
            len = strlen(word);
            if (len >= 3)
            {
                if (startsWith(word, prefix[0]) 
                        || startsWith(word, prefix[1])
                        || startsWith(word, prefix[2]))
                {
                    words[count] = (char *) malloc(len + 1);
                    strcpy(words[count++], word);
                }
            }
            word = strtok(NULL, del);
        }

        words[count] = (char *) malloc(2);
        strcpy(words[count++], "\n");

    } while (strcmp(line, "\n"));

    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(words[i], "\n") == 0)
        {
            printf("\n");
            continue;
        }
        printf("%s ", words[i]);
    }

    for (size_t i = 0; i < count; i++) free(words[i]);

    return EXIT_SUCCESS;
}
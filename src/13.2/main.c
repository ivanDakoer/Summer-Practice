#include "requires.h"

#define MAX 100

static int cmp(char *str)
{
    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i] < str[i - 1]) return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    FILE *input;
    char *buf;
    const char *del = " ,.:;!?\n\r\t";
    char *words[MAX];

    if (argc != 2)
    {
        printf("usage: 13.2.exe <file name>");
        return EXIT_FAILURE;
    }

    fopen_s(&input, argv[1], "rt");
    if (input == NULL)
    {
        printf("Can't open this file.");
        return EXIT_FAILURE;
    }

    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    buf = (char *) malloc(size + 1);

    fseek(input, 0, SEEK_SET);
    size = fread(buf, 1, size, input);
    buf[size] = 0;

    fclose(input);

    int count = 0;

    char *word = strtok(buf, del);
    while (word != NULL)
    {
        int i = 0;
        while (i < count)
        {
            if (strcmp(words[i], word) == 0) break;
            i++;
        }

        if (i == count)
        {
            if (i == MAX) return EXIT_FAILURE;

            int len = strlen(word);
            if (len > 0)
            {
                words[count] = (char *) malloc(len + 1);
                strcpy(words[count++], word);
            }
            else
            {
                len = 0;
            }
        }

        word = strtok(NULL, del);
    }


    for (int i = 0; i < count; i++) 
    {   
        if (cmp(words[i])) printf("\n%s", words[i]);
    }
    for (int i = 0; i < count; i++) free(words[i]);
    free(buf);

    return EXIT_SUCCESS;
}
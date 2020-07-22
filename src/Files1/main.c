#include "stack.h"

typedef char * string;

#define MAX 100

int main(int argc, char *argv[])
{
    
    FILE *input;
    string buf;
    string words[MAX];
    const char *del = " ,.:;!?\n\r\t";

    if (argc != 2)
    {
        printf("usage: .\\File1 <file name>");
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
    buf = (string) malloc(size + 1);

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


    int maxLen = strlen(words[0]);
    for (int i = 0; i < count; i++)
    {
        maxLen = strlen(words[i]) > maxLen ? strlen(words[i]) : maxLen;
    }

    for (int len = 1; len <= maxLen; len++)
    {
        for (int i = 0; i < count; i++)
        {
            if (strlen(words[i]) == len)
            {
                printf("%s\n", words[i]);
            } 
        }
    }
}
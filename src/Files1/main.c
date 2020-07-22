#include "stack.h"

typedef char * string;

int main(int argc, char *argv[])
{
    
    FILE *input;
    string buf = (string) malloc(256);
    Stack words;

    // if (argc != 2)
    // {
    //     printf("usage: .\\File1 <file name>");
    //     return EXIT_FAILURE;
    // }

    fopen_s(&input, "build/test1.txt", "rt");
    if (input == NULL)
    {
        printf("Can't open this file.");
        return EXIT_FAILURE;
    }

    while (!feof(input));
    {
        fscanf(input, "%s", buf);
        Push(&words, (const undefined)&buf, sizeof buf);
    }

    int maxLen = 0;
    for (Node *word = words; word != NULL; word = word->next)
    {
        maxLen = strlen((string)word) > maxLen ? strlen((string)word) : maxLen;
    }

    for (int len = 1; len <= maxLen; len++)
    {
        for (Node *word = words; word != NULL; word = word->next)
        {
            if (strlen((string)word) == len)
            {
                printf("%s\n", ((string)word));
            } 
        }
    }
}
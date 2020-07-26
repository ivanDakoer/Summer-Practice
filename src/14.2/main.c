#include "requires.h"

#define MAX 100

int main(int argc, char *argv[])
{
    FILE *input, *output;
    const char *sep = "\n\r\t ";
    char *buf, *words[MAX], *word;
    size_t size, count, len;

    if (argc != 2)
    {
        printf("usage: 14.2.exe <file name>");
        return EXIT_FAILURE;
    }

    fopen_s(&input, argv[1], "rt");
    if (input == NULL)
    {
        printf("Can't open input file.");
        return EXIT_FAILURE;
    }

    fseek(input, 0, SEEK_END);
    size = ftell(input);

    buf = (char *) malloc(size + 1);
    fseek(input, 0, SEEK_SET);
    size = fread(buf, 1, size, input);
    buf[size] = 0;

    fclose(input);

    count = 0;
    word = strtok(buf, sep);
    while (word != NULL)
    {
        len = strlen(word);
        if (len > 0)
        {
            if (word[0] == word[strlen(word) - 1])
            {
                words[count] = (char *) malloc(len + 1);
                strcpy(words[count++], word);
            }
        }
        else
        {
            len = 0;
        }

        word = strtok(NULL, sep);
    }
    free(buf);

    fopen_s(&output, "output.txt", "wt");
    if (output == NULL)
    {
        printf("Can't open output file.");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < count; i++)
    {
        fprintf(output, "%s\n", words[i]);
    }

    fclose(output);

    for (size_t i = 0; i < count; i++) free(words[i]);

    return EXIT_SUCCESS;
}
// Розробити дві консольну програми для розв’язання задачі згідно варіанту. Перша програма вхідні дані читає із стандартного потоку введення, результат записується у стандартний потік виведення. Друга програма вхідні дані читаютає з файлу, результат записується у новий файл. Ім’я файлів передаються через командний рядок, або вводяться з консолі. 

// Задано текст із малих латинських літер, слова в якому розділені пробілами і розділовими знаками. Розробити програму, яка знаходить і друкує всі слова з літерами, розміщеними в лексикографічному порядку.

#include "requires.h"

#define MAX 100

int compare(const void *arg1, const void *arg2)
{
    char **str1, **str2;
    str1 = (char**)arg1;
    str2 = (char**)arg2;
    return strcmp(str1[0], str2[0]);
}

int main(int argc, char *argv[])
{
    
    FILE *input;
    char *buf;
    const char *del = " ,.:;!?\n\r\t";
    char *words[MAX];

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

    qsort(words, count, sizeof(char *), compare);


    for (int i = 0; i < count; i++) printf("\n%s", words[i]);
    for (int i = 0; i < count; i++) free(words[i]);
    free(buf);

    return EXIT_SUCCESS;
}
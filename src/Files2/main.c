// Розробити дві консольну програми для розв’язання задачі згідно варіанту. Перша програма вхідні дані читає із стандартного потоку введення, результат записується у стандартний потік виведення. Друга програма вхідні дані читаютає з файлу, результат записується у новий файл. Ім’я файлів передаються через командний рядок, або вводяться з консолі. 

// Задано текст із малих латинських літер, слова в якому розділені пробілами і розділовими знаками. Розробити програму, яка знаходить і друкує всі слова з літерами, розміщеними в лексикографічному порядку.

#include "stack.h"

typedef char * string;

int compare(const void *str1, const void *str2)
{
    return strcmp((string)str1, (string)str2);
}

int main(int argc, char *argv[])
{
    
    FILE *input;
    char buf[BUFSIZ];

    // if (argc != 2)
    // {
    //     printf("usage: .\\File1 <file name>");
    //     return EXIT_FAILURE;
    // }

    fopen_s(&input, "test1.txt", "rt");
    if (input == NULL)
    {
        printf("Can't open this file.");
        return EXIT_FAILURE;
    }

    const char *del = " ,.:;!?\n\t";

    Stack words;
    int count = 0;
    while (fgets(buf, BUFSIZ, input))
    {
        string str = strtok(buf, del);
        while (str != NULL)
        {
            // printf("%s ", str);
            Push(&words, (const undefined)str, strlen(str) + 1);
            count++;
            str = strtok(NULL, del);
        }
    }

    string *arr = (string *) calloc(count, sizeof(string));
    if (arr == NULL) return EXIT_FAILURE;

    int k = 0;

    for (Node *word = words; word != NULL; word = word->next)
    {
        arr[k] = calloc(strlen((string)word->data) + 1, sizeof(char));
        if (arr[k] == NULL) return EXIT_FAILURE;
        strcpy(arr[k], (string)word->data);
    }

    for (int i = 0; arr[i] != NULL; i++)
    {
        printf("%s\n", arr[i]);
    }

    Delete(&words);

    for (int i = 0; i < k; i++) free(arr[i]);
    free(arr);

    return EXIT_SUCCESS;
}
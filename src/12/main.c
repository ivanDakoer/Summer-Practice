#include "stack.h"

int isVowel(char c) { return strchr("AEIOUY", toupper(c)) != NULL; }

void deleteVowels(Stack *stack);

void printStack(Stack *stack);

int main()
{
    Stack myStack = NULL;

    char c;

    do {
        c = getchar();
        if (c == '\n') break;
        Push(&myStack, (const undefined)&c, sizeof c);
    } while (c != '\n');

    printf("\nSource:\n");
    printStack(&myStack);

    Stack newStack = NULL;

    for (Node *node = myStack; node; node = node->next)
    {
        if (isVowel((*(char *)node->data)) == 0)
        {
            Push(&newStack, node->data, sizeof node->data);
        }
    }


    deleteVowels(&myStack);
    
    printf("\nWithout vowels: \n");
    printStack(&myStack);

    Delete(&myStack);
    Delete(&newStack);
}

void deleteVowels(Stack *stack)
{
    Node *previous = *stack;
    for (Node *node = *stack; node; node = node->next)
    {
        if (isVowel(*(char *)(*stack)->data))
        {
            Pop(stack);
            node = *stack;
        }
        else if (isVowel(*(char *)node->data))
        {
            previous->next = node->next;
            node = previous;
        }
        previous = node;
    }
}

void printStack(Stack *stack)
{
    Node *node = *stack;
    while (node != NULL)
    {
        printf("%c", (*(char *)node->data));
        node = node->next;
    }
}
#include "stack.h"

int isVowel(char c) { return strchr("AEIOUY", toupper(c)) == 0; }

void deleteVowels(Stack *stack);

void printStack(Stack *stack);

int main()
{
    Stack myStack = NULL;
    

    char c;

    do {
        c = getchar();
        Push(&myStack, (const undefined)&c, sizeof c);
    } while (c != '\n');

    Node *node, *previous = myStack;

    printStack(&myStack);

    Stack newStack = NULL;

    for (Node *node = myStack; node->next; node = node->next)
    {
        if (isVowel((*(char *)node->data)) == 0)
        {
            Push(&newStack, node->data, sizeof node->data);
        }
    }

    deleteVowels(&myStack);
    
    printStack(&myStack);

    Delete(&myStack);
    // Delete(&newStack);
}

void deleteVowels(Stack *stack)
{
    Node *previous;
    for (Node *node = *stack; node->next; node = node->next)
    {
        if (isVowel(*(char *)(*stack)->data))
        {
            Pop(stack);
            node = *stack;
        }
        else if (isVowel(*(char *)node->data))
        {
            Node *tmp = previous->next;
            previous->next = tmp->next;
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
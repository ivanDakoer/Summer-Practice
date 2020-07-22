#ifndef __STACK_H__
#define __STACK_H__

#include "requires.h"

typedef struct Node 
{
    undefined data;
    struct Node *next;
} Node;


typedef Node *Stack;

void Push(Stack *head, const undefined data, size_t typeSize);

void Pop(Stack *head);

void Delete(Stack *head);

#endif
#include "stack.h"

void Push(Stack *head, const undefined data, size_t typeSize)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) return;

    node->data = malloc(typeSize);
    if (node->data == NULL) return;

    memcpy(node->data, data, typeSize);
    node->next = *head;
    *head = node;
}

void Pop(Stack *head)
{
    Node *previous = NULL;
    if (head == NULL) return;

    previous = *head;
    *head = (*head)->next;
    free(previous->data);
    free(previous);
}

void Delete(Stack *head)
{
    while ((*head)->next != NULL)
    {
        Node *tmp = *head;
        (*head) = (*head)->next;
	free(tmp->data);
	free(tmp);
    }

    free((*head)->data);
    free(*head);
    *head = NULL;
}
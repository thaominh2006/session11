//
// Created by Admin on 03/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data)
{
    Node* node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}
void printList(Node* head)
{
    Node* current = head;
    printf("NULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
Node *getAll(Node *head, int index)
{
    if (index < 0)
    {
        return NULL;
    }
    Node *current = head;
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current -> next;
    }
    return current;
}

int main()
{
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;
    third -> next = fourth;
    fourth -> prev = third;
    fourth -> next = fifth;
    fifth -> prev = fourth;

    printList(head);
    Node* findNode;

    findNode = getAll(head, 0);
    printf("Node 1: %d\n", findNode -> data);
    findNode = getAll(head, 1);
    printf("Node 2: %d\n", findNode -> data);
    findNode = getAll(head, 2);
    printf("Node 3: %d\n", findNode -> data);
    findNode = getAll(head, 3);
    printf("Node 4: %d\n", findNode -> data);
    findNode = getAll(head, 4);
    printf("Node 5: %d\n", findNode -> data);

    return 0;
}
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
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}
void printList(Node *head)
{
    Node *current = head;
    printf("NULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}
int getLength(Node *head)
{
    Node *current = head;
    int length = 0;
    while (current != NULL)
    {
        current = current -> next;
        length++;
    }
    return length;
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
    int length = getLength(head);
    printf("Danh sach lien ket co %d phan tu", length);
    return 0;
}
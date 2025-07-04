//
// Created by Admin on 03/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool searchList(Node* head, int searchTarget)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current -> data == searchTarget)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
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
    int value;
    printf("Nhap so nguyen duong ban muon tim: ");
    scanf("%d", &value);
    if (searchList(head, value)){
        printf("Phan tu %d co trong danh sach.\n", value);
    }else
    {
        printf("Phan tu %d khong co trong danh sach.\n", value);
    }
    return 0;
}

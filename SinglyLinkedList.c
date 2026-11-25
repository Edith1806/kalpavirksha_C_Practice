#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node * createNode(int val)
{
    struct Node *node = malloc(sizeof(*node));
    if(node == NULL) return NULL;
    node->data = val;
    node->next = NULL;
    return node;
}

void insertAtBeg(int val)
{
    struct Node *newNode = createNode(val);
    if(newNode == NULL) return;
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
    return;
}

void insertAtEnd(int val)
{
    struct Node *newNode = createNode(val);
    if(newNode == NULL) return;
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    struct Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPos(int val, int pos)
{
    
    if(pos == 0){
        insertAtBeg(val);
        return;
    }

    if(pos < 0)
    {
        printf("Invalid Position!\n");
        return;
    }
    if(head == NULL) 
        return;

    struct Node *current = head;
    for(int i = 0; i < pos -1 && current != NULL; i++)
    {
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Position invalid!\n");
        return;
    }
    struct Node *newNode = createNode(val);

    if(newNode == NULL)
        return;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBeg()
{
    if(head == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if(head == NULL || head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *current = head;
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteAtPos(int pos)
{
    if(pos == 0){
        deleteAtBeg();
        return;
    }
    if(pos < 0)
    {
        printf("Invalid Position!\n");
        return;
    }
    struct Node *current = head;
    struct Node *prev = NULL;

   for(int i = 0; i < pos && current != NULL; i++)
   {
    prev = current;
    current = current->next;
   }

    if(current == NULL)
    {
        printf("Deletion unsucessful!\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void display()
{
    if(head == NULL)
        return;

    struct Node *curr = head;
    while(curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
}

int main(void)
{

    insertAtBeg(10);
    insertAtBeg(20);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtPos(30, 3);
    insertAtPos(70,5);
}
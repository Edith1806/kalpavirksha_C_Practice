
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
        return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(Node **head, int val)
{
    Node *newNode = createNode(val);
    if(newNode == NULL)
        return;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int val)
{
    Node *newNode = createNode(val);
    if(newNode == NULL)
        return;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while(current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void insertAtPos(Node **head, int val, int pos)
{
    if(pos < 0)
        return;
    if(pos == 0)
    {
        insertAtBeg(head, val);
        return;
    }
    Node *current = *head;
    for(int i = 0; i < pos - 1 && current != NULL; i++)
        current = current->next;
    if(current == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    Node *newNode = createNode(val);
    if(newNode == NULL)
        return;
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtBeg(Node **head)
{
    if(*head == NULL)
        return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(Node **head)
{
    if(*head == NULL)
        return;
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    while(current->next->next != NULL)
        current = current->next;
    Node *temp = current->next;
    current->next = NULL;
    free(temp);
}

void deleteAtPos(Node **head, int pos)
{
    if(pos < 0 || *head == NULL)
        return;
    if(pos == 0)
    {
        deleteAtBeg(head);
        return;
    }
    Node *current = *head;
    Node *prev = NULL;
    for(int i = 0; i < pos && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }
    if(current == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

void display(Node *head)
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node **head)
{
    while(*head != NULL)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void reverseList(Node **head)
{
    if(head == NULL || *head == NULL) return;

    Node *current = *head;
    Node *nxt = NULL;
    while(current != NULL)
    {
       Node *temp = current->next;
       current->next = nxt;
       nxt = current;
       current = temp;
    }
    *head = nxt;
}



bool detectCycle(Node *head)
{
    if(head == NULL) return false;
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

Node * findNthElementFromEnd(Node *head, int n)
{
    if(head == NULL || n <= 0)
        return NULL;
    
    Node *first = head, *second = head;
    while(n--> 0 && first != NULL)
    {
        first = first->next;
    }
    if(n > 0)
    {
        printf("Position Invalid!\n");
        return NULL;
    }

    while(first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    return second;
}

Node * findMiddleNode(Node *head)
{
    if(head == NULL)
        return NULL;
    
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *search(Node *head, int val)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node *current = head;
    while(current != NULL)
    {
        if(current->data == val)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeDuplicates(Node *head)
{
    if(head == NULL)
        return;
    
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL)
    {
       if(prev != NULL && current->data == prev->data)
       {
           prev->next = current->next;
            Node *temp = current;
            current = current->next;
            free(temp);
       }
       else{
            prev = current;
            current = current->next;
       }
    }
}

Node *getIntersection(Node *headA, Node *headB)
{
    if(headA == NULL || headB == NULL)
        return NULL;
    
    Node *currA = headA, *currB = headB;
    while(currA != currB)
    {
        currA = (currA == NULL)? headB: currA->next;
        currB = (currB == NULL)? headA: currB->next;
    }
    return currA;
}

Node * reverseLinkedListFirstKElements(Node * head, int k)
{
    if(k < 0 || head == NULL)
        return NULL;
    if(k == 0)
        return head;
    
    Node *current = head;
    Node *nxt = head;
    int traverse = k;
    for(int i = 0; i < k; i++){
        if(nxt == NULL)
            return head;
        nxt = nxt->next;
    }

    while(current != NULL && k-->0)
    {
       Node *rem = current->next;
       current->next = nxt;
       nxt = current;
       current = rem;
    }
    return nxt;
}

Node* reverseLinkedListInGroupK(Node *head, int k)
{
    if(head == NULL || k <= 1)
        return head;
    Node dummy;
    dummy.next = head;
    Node *groupPrev = &dummy;
    while(1)
    {
        Node *groupEnd = groupPrev;
        for(int i = 0; i < k && groupEnd != NULL; i++)
        {
            groupEnd = groupEnd->next;
        }
        if(groupEnd == NULL)
            break;
        Node *groupNext = groupEnd->next;
        Node *prev = groupNext;
        Node *current = groupPrev->next;
        while(current != groupNext)
        {
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        Node *oldGroupStart = groupPrev->next;
        groupPrev->next = groupEnd;
        groupPrev = oldGroupStart;
    }

    return dummy.next;
}

int count_nodes(Node *head)
{
    if(head == NULL) return 0;
    Node *current = head;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main(void)
{
    Node *head = NULL;
    insertAtBeg(&head, 10);
    insertAtBeg(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPos(&head, 25, 2);
    printf("Original list: ");
    display(head);
    deleteAtBeg(&head);
    printf("After deleting beginning: ");
    display(head);
    deleteAtEnd(&head);
    printf("After deleting end: ");
    display(head);
    deleteAtPos(&head, 1);
    printf("After deleting position 1: ");
    display(head);
    freeList(&head);

    return 0;
}

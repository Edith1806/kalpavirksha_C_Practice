#include<stdio.h>
#define max 100

struct stack
{
    int data[max];
    int top;
};

void push(struct stack *st, int val)
{
    if(st->top == max - 1)
    {
        printf("overflow...");
        return;
    }
    st->data[++st->top] = val;
}

int pop(struct stack *st)
{
    if(st->top == -1)
    {
        printf("underflow..");
        return -1;
    }
    return st->data[st->top--];
}
int main()
{
    struct stack numbr;
    numbr.top = -1;
    push(&numbr,10);
    push(&numbr, 20);
    printf("%d %d", pop(&numbr), pop(&numbr));
}

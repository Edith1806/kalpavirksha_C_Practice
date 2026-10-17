#include<stdio.h>

int divide_with_shift(int number)
{
    return number >> 2;
}

int main(void)
{
    int number;
    scanf("%d", &number);
    printf("%d",divide_with_shift(number));
    return 0;
}
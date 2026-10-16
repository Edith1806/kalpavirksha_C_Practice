#include<stdio.h>

int get_square(int number)
{
    return number * number;
}

int main(void)
{
    int number;
    scanf("%d",&number);
    printf("%d",get_square(number));
    return 0;
}
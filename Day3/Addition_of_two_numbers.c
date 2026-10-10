#include<stdio.h>

int add_two_numbers(int num1, int num2)
{
    return num1 + num2;
}

int main(void)
{
    int num1, num2;
    scanf("%d\n%d",&num1,&num2);
    printf("%d",add_two_numbers(num1, num2));
    return 0;
}
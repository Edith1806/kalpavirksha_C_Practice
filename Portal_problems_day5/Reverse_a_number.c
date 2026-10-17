#include<stdio.h>

int main(void)
{
    int number;
    scanf("%d", &number);
    int reminder, reversed_num = 0;
    while(number > 0)
    {
        reminder = number % 10;
        reversed_num = reversed_num * 10 + reminder;
        number /= 10;
    }
    printf("%d", reversed_num);
}
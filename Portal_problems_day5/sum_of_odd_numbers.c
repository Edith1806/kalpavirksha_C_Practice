#include<stdio.h>

int sum_of_oddNum(int number)
{
    int sum = 0;
    for(int current_num = 1; current_num <= number; current_num += 2)
    {
        sum += current_num;
    }
    return sum;
}

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("Sum of Odd Numbers from 1 to %d: %d", num, sum_of_oddNum(num));
    return 0;
}
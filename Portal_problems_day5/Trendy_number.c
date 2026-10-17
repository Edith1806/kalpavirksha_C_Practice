#include<stdio.h>
#include<stdbool.h>

bool is_trendy_number(int num)
{
    if((num >= 100 && num <= 999) || (num >= -999 && num <= -100))
    {
        num /= 10;
        if((num % 10) % 3 == 0)
            return true;
    }
    return false;
}

int main(void)
{
    int number;
    scanf("%d", &number);
    if(is_trendy_number(number))
    {
        printf("Trendy Number");
    }
    else
    {
        printf("Not a Trendy Number");
    }
    return 0;
}
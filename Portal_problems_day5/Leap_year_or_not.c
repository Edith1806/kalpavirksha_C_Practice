#include<stdio.h>
#include<stdbool.h>

bool isLeapYear(int year)
{
    if((year%100 != 0 && year % 4 == 0) || year % 400 == 0)
    {
        return true;
    }
    return false;
}

int main(void)
{
    int year;
    scanf("%d", &year);
    if(isLeapYear(year))
    {
        printf("%d is a leap year", year);
    }
    else
    {
        printf("%d is not a leap year", year);
    }
    return 0;
}
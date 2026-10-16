#include<stdio.h>

int get_area_of_rectangle(int length, int breadth)
{
    return length * breadth;
}

int main(void)
{
    int length, breadth;
    scanf("%d %d",&length, &breadth);
    printf("Area of rectangle is %d",get_area_of_rectangle(length, breadth));
    return 0;
}
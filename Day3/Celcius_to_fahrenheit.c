#include<stdio.h>

float celcius_to_fahrenheit(float celcius)
{
    return ((celcius * 9)/5) + 32;
}

int main(void)
{
   float celcius;
   scanf("%f",&celcius);
   printf("Temperature in Fahrenheit is: %.2f",celcius_to_fahrenheit(celcius));
   return 0;
}
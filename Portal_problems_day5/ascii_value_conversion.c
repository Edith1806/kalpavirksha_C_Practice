#include<stdio.h>

int main(void)
{
    char character;
    scanf("%c", &character);
    int ascii_value = character;
    printf("The ASCII value of %c is: %d", character, ascii_value);
    return 0;
}
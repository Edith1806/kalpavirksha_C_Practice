#include<stdio.h>
#include<limits.h>


void get_second_smallest_element(int num_array[], int no_of_elements)
{
    int min = num_array[0];
    int second_min = INT_MAX;
    int found_second_min = 0;
    for(int idx = 1; idx < no_of_elements; idx++)
    {
        int current_element = num_array[idx];
        if(min > current_element)
        {
            second_min = min;
            min = current_element;
            found_second_min = 1;
        }

        else if(min != current_element && second_min >= current_element)
        {
            second_min = current_element;
            if(found_second_min == 0)
                found_second_min = 1;
        }
    }
        if(!found_second_min)
            printf("No second smallest element found\n");
        else
            printf("%d is the second smallest element in the array.\n",second_min);
}

int main(void)
{
    int number_of_elements;
    printf("Enter the number of elements:");
    if(scanf("%d", &number_of_elements) != 1)
    {
        printf("Invalid Input\n");
        return 0;
    }
    if(number_of_elements <= 1)
    {
        printf("No second smallest element.\n");
        return 0;
    }

    int num_array[number_of_elements];
    printf("\nEnter the array elements:");
    for(int idx = 0; idx < number_of_elements; idx++)
    {
        if(scanf("%d", &num_array[idx]) != 1)
        {
            printf("Invalid Input\n");
            return 0;
        }
    }
    get_second_smallest_element(num_array, number_of_elements);
}
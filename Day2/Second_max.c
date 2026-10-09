#include<stdio.h>
#include<limits.h>


void get_second_largest_element(int num_array[], int no_of_elements)
{
    int max = num_array[0];
    int second_max = INT_MIN;
    int found_second_max = 0;
    for(int idx = 1; idx < no_of_elements; idx++)
    {
        int current_element = num_array[idx];
        if(max < current_element)
        {
            second_max = max;
            max = current_element;
            found_second_max = 1;
        }

        else if(max != current_element && second_max <= current_element)
        {
            second_max = current_element;
            if(found_second_max == 0)
                found_second_max = 1;
        }
    }
        if(!found_second_max)
            printf("No second largest element found\n");
        else
            printf("%d is the second largest element in the array.\n",second_max);
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
        printf("No second largest element.\n");
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
    get_second_largest_element(num_array, number_of_elements);
}
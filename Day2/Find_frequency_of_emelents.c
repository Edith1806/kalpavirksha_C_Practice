#include<stdio.h>

int count_occurrence(int start_idx, int count_number, int arr[], int visited[], int no_of_elements)
{
    int count = 1;
    for(int i = start_idx; i < no_of_elements; i++)
    {
        if(arr[i] == count_number){
            count++;
            visited[i] = 1;
        }
    }
    return count;
}

void print_elements_frequency(int arr[], int no_of_elements)
{
    int visited[no_of_elements];
    for(int i = 0; i < no_of_elements; i++)
    {
        visited[i] = 0;
    }
    for(int i = 0; i < no_of_elements; i++)
    {
        if(visited[i]) continue;
        visited[i] = 1;
        int count = count_occurrence((i + 1),arr[i], arr, visited, no_of_elements);
        printf("%d occurred %d\n",arr[i], count);
    }
}

int main(void)
{
    int no_of_elements;
    printf("Enter the no_of_elements:");
    if(scanf("%d", &no_of_elements) != 1)
    {
        printf("Invalid Input\n");
        return 0;
    }
    if(no_of_elements <= 0)
    {
        printf("Invalid no of elements\n");
        return 0;
    }

    int arr[no_of_elements];
    for(int i = 0; i < no_of_elements; i++)
    {
        if(scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid Input\n");
            return 0;
        }
    }

    print_elements_frequency(arr, no_of_elements);
    return 0;
}
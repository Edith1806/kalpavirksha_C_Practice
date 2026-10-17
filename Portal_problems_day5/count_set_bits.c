#include<stdio.h>

int count_set_bits(int n)
{
    int count = 0;
    while(n > 0)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main(void)
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case-- > 0)
    {
        int num;
        int tot_count = 0;
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
        {
            tot_count += count_set_bits(i);
        }
        printf("%d", tot_count);
    }
    return 0;
}
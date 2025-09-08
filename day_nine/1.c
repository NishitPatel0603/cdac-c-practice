#include <stdio.h>

int main()
{
    int arr[6];
    int *p = arr;

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = *p;
    int max = *p;
    for (int i = 0; i < 6; i++)
    {
        if (min > *(p++))
        {
            min = arr[i];
        }
        if (max < *(p++))
        {
            max = arr[i];
        }
    }
    
    printf("min = %d\n", min);
    printf("max = %d\n", max);
}
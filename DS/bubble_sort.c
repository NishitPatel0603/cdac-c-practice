#include <stdio.h>
int main()
{
    int arr[] = {3, 9, 7, 5, 1, 2, 8};
    int i, j, temp;
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
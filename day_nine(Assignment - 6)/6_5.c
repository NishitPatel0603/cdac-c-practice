#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5,6};
    int arr1[6];
    int *ptr = arr;
    for (int i = 0; i < 6; i++)
    {
        arr1[i] = *ptr;
        ptr++;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("orignal = %d\n",arr[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("copy = %d\n",arr1[i]);
    }
    
}
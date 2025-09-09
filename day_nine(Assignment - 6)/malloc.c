#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int *arr = (int *) malloc (a*sizeof(a));
    if (arr == NULL)
    {
        printf("memory allocation failed");
        return 1;

    }
    for (int i = 0; i < a; i++)
    {
        printf("enter the valur of %d\n",i);
        scanf("%d", &arr[i]);
        
    }
    for (int i = 0; i < a; i++)
    {
        printf("the value present in the array are %d\n", arr[i]);
    }
    free(arr);
    


}
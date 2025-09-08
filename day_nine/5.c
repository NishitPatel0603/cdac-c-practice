#include <stdio.h>
void swap(int *ptr , int *ptr1)
{
    int temp = 0;
    temp = *ptr;
    *ptr = *ptr1;
    *ptr1 = temp;

}

int main()
{   int a = 12;
    int b = 14;

    swap(&a, &b);
    printf("%d \t %d", a,b );
}
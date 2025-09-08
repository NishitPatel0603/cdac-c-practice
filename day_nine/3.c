#include <stdio.h>

int main()
{
    int a = 12;
    int *ptr = &a;
    char b ='1';
    char *ptr1 = &b;
    float c = 12.1;
    float *ptr2 = &c;

    printf("the address is %p and value is %d\n", ptr,a);
    printf("the address is %p and value is %c\n", ptr1,b);
    printf("the address is %p and value is %f\n", ptr2,c);

}
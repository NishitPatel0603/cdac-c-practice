#include <stdio.h>

int main()
{
    int n, i = 0;
    printf("Enter the number\n");
    scanf("%d", &n);
    if (n & 1 == 0)
    {
        printf("It is odd number"); // see a number is odd then its lsb is 1 if we do & opertaion then if it is zero then only you will get 0.
    }
    else
    {
        printf("it is even number ");
    }

    return 0;
}
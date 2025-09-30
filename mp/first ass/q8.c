#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Enter the number's to swap\n");
    scanf("%d %d", &a, &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("swapped number are %d and %d", a, b);
}

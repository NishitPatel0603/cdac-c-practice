#include <stdio.h>
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int i, n;
    printf("enter the value you want :");
    scanf("%d", &n);
    printf("Fibomacchi seris ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", fib(i));
    }
    printf("\n");
}

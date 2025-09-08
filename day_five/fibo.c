#include <stdio.h>

int fibo(int upper)
{
    int result;
    if (upper <= 1)
        return upper;

    return fibo(upper - 1) + fibo(upper - 2);
}

int main()
{
    printf("%d\n", fibo(10));
    return 0;
}
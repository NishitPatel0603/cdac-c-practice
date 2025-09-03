#include <stdio.h>

int prime(int x)
{
    if (x <= 1)
        return 0; // numbers <= 1 are not prime

    // check all numbers from 2 up to x-1
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0; // divisible → not prime
        }
    }

    return 1; // no divisors found → prime
}

void fibo(int upper, int lower)
{
    int a = 0, b = 1, result;

    for (int i = 2; i <= upper; i++)
    {
        result = a + b;
        a = b;
        b = result;

        if (i >= lower && prime(result))
        {
            printf("%d\n", result);
        }
    }
}

int main()
{
    fibo(5, 1);
    return 0;
}

#include <stdio.h>

int prime(int x)
{
    if (x <= 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
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
    fibo(15, 10);
    return 0;
}

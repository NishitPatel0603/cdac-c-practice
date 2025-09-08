#include <stdio.h>
int sum_of_n(int);
int main()
{
    int n;
    printf("enter the value you want :");
    scanf("%d", &n);

    printf("%d", sum_of_n(n));
}

int sum_of_n(int x)
{
    int result;
    if (x == 0)
    {
        return 0;
    }
    else
    {
        result = (x + sum_of_n(x - 1));
        return result;
    }
}
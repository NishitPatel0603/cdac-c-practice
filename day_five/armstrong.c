#include <stdio.h>
#include <math.h>

int main()
{
    int num, loop = 0, use;
    double num1 = 1, strong = 0;
    scanf("%d", &num);
    use = num;
    while (num > 0)
    {
        int num1 = num % 10;
        loop++;
        num /= 10;
    }
    num = use;

    while (num > 0)
    {
        num1 = num % 10;
        strong += pow(num1, loop);
        num /= 10;
    }
    num = use;
    if ((int)strong == num)
    {
        printf("it is a amstrong number");
    }
    else
    {
        printf("it is not");
    }
}
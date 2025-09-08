#include <stdio.h>

int main()
{
    int sum = 0;
    int num;
    int i = 1;
    scanf("%d", &num);
    while (i <= num)
    {
        if (i % 2 != 0)
        {
            sum += i;
        }
        i++;
    }
    printf("%d", sum);
}
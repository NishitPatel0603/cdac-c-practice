#include <stdio.h>
int digit(int, int);
int main()
{
    int num, sum = 0;
    printf("enetr the number :");
    scanf("%d", &num);
    printf("%d\n", digit(num, sum));
}
int digit(int x, int sum)
{
    int y;

    if (x > 0)
    {
        y = x % 10;
        sum += y;
        return digit(x / 10, sum);
    }
}
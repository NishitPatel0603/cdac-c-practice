#include <stdio.h>
int main()
{
    int num, add = 0, i;
    printf("enter the number ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        if (i % 5 == 0)
        {
            continue;
        }
        add += i;
    }
    printf("%d", add);
}
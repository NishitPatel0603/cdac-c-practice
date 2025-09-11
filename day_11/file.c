#include <stdio.h>

int main()
{
    int num, count = 0, tem, result = 0, mul;

    printf("Enter the number: ");
    scanf("%d", &num);

    for (tem = num; tem > 0; tem /= 10)
    {
        count++;
    }

    tem = num;
    while (tem > 0)
    {
        int digit = tem % 10;
        mul = 1;

        for (int i = 0; i < count; i++)
        {
            mul *= digit;
        }

        result += mul;
        tem /= 10;
    }

    if (result == num)
    {
        printf("it is\n");
    }
    else
    {
        printf("it's not\n");
    }
    
    return 0;
}

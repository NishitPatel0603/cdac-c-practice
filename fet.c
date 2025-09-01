#include <stdio.h>

int main()
{
    int fac = 5, mul =1;
    for (int i = 1; i <=fac; i++)
    {
        mul = mul * i;
        
    }
    printf("%d\n",mul);
}
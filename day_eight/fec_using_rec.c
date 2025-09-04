#include <stdio.h>
int fact(int);
int main()
{
    int fac;
    printf("enter the value you want :");
    scanf("%d",&fac);

    printf("%d",fact(fac));
}

int fact(int x)
{
    int result;
    if(x == 0)
    {
        return 1;
    }
    else
    {
        result = (x * fact(x-1));
        return result;
    }
    
}
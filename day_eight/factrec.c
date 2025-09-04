#include <stdio.h>
int fact(int);
int main()
{
    int fac;
    printf("enter the value you want :");
    scanf("%d",&fac);
    fact(fac);
    for (int i = 2; i <= fac; i++)
    {
        printf("%d\t",fac);
    }
    
    
}

int fact(int x)
{
    int result=0;
    if(x <= 1)
    {
        return x;
    }
    return result = fact(x-1) + fact(x-2);
       
}
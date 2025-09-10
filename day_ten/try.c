#include<stdio.h>

int addDigits(int num) 
{
    int a = 0 ;
    if(num == 0)
    {
        return 0;
    }
    a = (num % 10) + addDigits(num / 10);
    
    if (a >= 10)
    {
        return addDigits(a);
    }
    else
    {
        return a;
    }   
}

int main()
{
    printf("%d\n", addDigits(38));
}
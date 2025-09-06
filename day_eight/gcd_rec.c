#include<stdio.h>
int gcd(int x,int y)
{
    int a;
    if (y == 0)
    {
       return x;
    }
    else
    {
        return gcd(y,x % y);
    }
    
    
}
int main()
{
    int x = 36;
    int y = 26;
    printf("%d",gcd(x ,y));
    return 0;
} 

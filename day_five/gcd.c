#include<stdio.h>
int gcd(int x,int y)
{
    int a;
    while (y != 0)
    {
        a = x % y;
        x = y;
        y = a;
    }
    return x;
}
int main()
{
    int x = 60;
    int y = 36;
    printf("%d",gcd(x ,y));
    return 0;
} 

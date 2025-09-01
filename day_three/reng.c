#include<stdio.h>
int main()
{
    int a,b,i,sum=0;
    printf("enter two numbers :");
    scanf("%d %d",&a,&b);
    for ( i = a; i <= b; i++)
    {
        sum += i;
    }
    printf("sum is %d",sum);
}
#include<stdio.h>
int power(int,int);
int power(int n,int i)
{
    int result;
    if(i == 0)
    {
        return 1;
    }
    result = n*power(n,i-1);
    return  result;
}
int main()
{
    int a,n,i;
    printf("enter the value you want :");
    scanf("%d %d",&n,&i);
    printf("Power of number ");
    
    printf("%d\t",power(n,i));
    
    printf("\n");
    return 0;
}

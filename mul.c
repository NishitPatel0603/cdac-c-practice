#include<stdio.h>
int main(){
int a,b,sum,sub,mul,w;
float div;

printf("enter any two numbers\n");
scanf("%d %d",&a,&b);
printf("enter 1 for sum\n");
printf("enter 2 for sub\n");
printf("enter 3 for mul\n");
printf("enter 4 for div\n");
scanf("%d",&w);

switch (w)
{
case 1:
    sum=a+b;
    printf("%d",sum);
    break;

case 2:
    sub=a-b;
    printf("%d",sub);
    break;

case 3:
   mul=a*b;
   printf("%d",mul);
   break;
case 4:
   div = (float)a / b;
   printf("%f",div);

   break;
default:
    break;
}
}

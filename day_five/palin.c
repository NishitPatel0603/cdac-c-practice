#include<stdio.h>

int main()
{
    int num, man, temp, rev = 0;
    scanf("%d", &num);
    temp = num;
    while (num>0)
    {
       man = num % 10;
       rev = rev*10 + man;
       num /= 10;

    }
    if (temp == rev)
    {
        printf("it is palindrome");
    }
    else
    {
        printf("it is not palindrome");
    }
    

}
// #include<stdio.h>
// int main()
// {
//     int num1=0,num2=0,user=0;
//     printf("Enter the number :");
//     scanf("%d",&user);
//         num1=user%10;
//         //printf("%d\n", num1);
//         user=user/10;
//         num2=user%10;
//         //printf("%d\n", num2);
//     printf("%d\n",num1+num2);

// }

#include <stdio.h>
int main()
{
    int num1 = 0, user, sum = 0;
    printf("Enter the number :");
    scanf("%d", &user);
    while (user > 0)
    {
        num1 = user % 10;
        sum = sum + num1;
        user = user / 10;
    }
    printf("%d", sum);
}
#include <stdio.h>
#include <ctype.h>

int main()
{
    char num;
    printf("enter anything\n");
    scanf("%c", &num);
    if (isalpha(num))
    {
        printf("it is alphabet and its ascii value is %d\n", num);
    }
    else if (isdigit(num))
    {
        printf("it is a number and its ascii value is %d\n", num);
    }
    else
    {
        printf("nothing");
    }
}
#include <stdio.h>

void revstr(char *str)
{
    int l = 0;
    for (int i = 0; i < 100; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        else
        {
            l++;
        }        
    }    
    char temp;
    for (int i = 0; i < l / 2; i++)
    {
        temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }
    printf("after %s\n", str);
}

int main()
{
    char st[100];
    printf("enter the string :");
    scanf("%s", st);

    printf("it is original string %s\n", st);
    revstr(st);

    return 0;
}
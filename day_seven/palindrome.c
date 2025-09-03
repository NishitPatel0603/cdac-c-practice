#include <stdio.h>
#include <string.h>
int main()
{
    char wor[20];
    int len, i, temp;
    printf("enter the word\n");
    scanf("%s", wor);
    char same[20];
    strcpy(same,wor);
    len = strlen(wor);
    for (i = 0; i < len / 2; i++)
    {
        temp = wor[i];
        wor[i] = wor[len - 1 - i];
        wor[len - 1 - i] = temp;
    }
    if (strcmp(wor,same))
    {
        printf("it is not a palindorme");
    }
    else
    {
        printf("it is a palindrome\n");
    }
}
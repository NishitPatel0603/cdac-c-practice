#include<stdio.h>
#include<string.h>
int palindrom(char *_str,int left,int right)
{
    if(left >= right)
    {
        return 1;
    }
    if(_str[left] != _str[right])
    {
        return 0;
    }
    left++;
    right--;
    return palindrom(_str,left,right);   
}
int main()
{
    char _str[100];
    int left,right;
    printf("enetr a string :");
    scanf("%s",_str);
    left = 0;
    right = strlen(_str)-1;
    if (palindrom(_str,left,right))
    {
        printf("%s is a palindrom ",_str);
    }
    else
    {
        printf("%s is not a palindrom ",_str);
    }
    return 0;
}


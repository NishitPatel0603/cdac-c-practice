#include <stdio.h>
#include <string.h>
void vowel(char *inp)
{
    char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vow = 0;

    for (int i = 0; i < strlen(arr); i++)
    {
        for (int j = 0; j < strlen(inp); j++)
        {
            if (arr[i] == *(inp + j))
            {
                vow++;
            }
            if (arr[j] == '\0')
            {
                break;
            }
        }
    }
    printf("there are %d vowels in the word", vow);
}

int main()
{
    char inp[100];
    printf("enter the string\n");
    scanf("%s", &inp);
    vowel(&inp);
}
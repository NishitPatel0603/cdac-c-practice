#include <stdio.h>

int main() 
{
    char word[100];
    printf("Enter the word you want to convert to Uppercase\n");
    scanf("%s", word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] & (1<<5)) // checking whether 
        {
            word [i] = word[i] & ~(1<<5); //Here just make the 5 bit '0' to make it uppercase
        }
        
    }
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%s",word[i]);
    }
    
    return 0;
}
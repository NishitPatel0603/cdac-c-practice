#include <stdio.h>

int main()
{
    int num = 0, mask = 0, pos = 0;
    printf("Enter the number\n");
    scanf("%d", &num);
    printf("Enter the position of num to set\n");
    scanf("%d", &pos);
    pos = pos -1; // normalizing the input for user
    mask = ~(1 << pos); // create mask with 0 at pos
    num = num & mask;   // clear the bit
    printf("%d\n", num);

    return 0;
}
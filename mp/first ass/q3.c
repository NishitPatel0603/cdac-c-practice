#include <stdio.h>

int main()
{
    int num = 0, mask = 0, pos = 0;
    printf("Enter the number\n");
    scanf("%d", &num);
    printf("Enter the position of num to set\n");
    scanf("%d", &pos);

    mask = 1 << pos;       // making mask using 1 shifting according to position
    if ((num & mask) != 0) // checking whether bit already set or not
    {
        printf("the bit is already set\n");
    }
    else
    {
        num = num | mask; // using mask for setting the bit
    }
    printf("%d\n", num);

    return 0;
}
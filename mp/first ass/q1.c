#include <stdio.h>

int main()
{
    int n, i = 0;
    int arr[32];
    printf("Enter the number\n");
    scanf("%d", &n);
    while (n != 0) // checking until the n is not zero.
    {
        arr[i] = n & 1; // using to store the LSB
        n = n >> 1;     // using to shift the bit right
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]); // printing loop.
    }

    return 0;
}
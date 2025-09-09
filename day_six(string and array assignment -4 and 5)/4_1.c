#include <stdio.h>

int main() {
    int sum;
    int a [] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++)
    {
        sum = sum + a[i];
        
    }
    printf("%d", sum);
}
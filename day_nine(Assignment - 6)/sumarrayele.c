#include <stdio.h>

int main() {
    int sum;
    int a [] = {1,2,3,4,5,6,7,8,9,10};
    int *p = a;
    int psum;

    for (int i = 0; i < 10; i++)
    {
        sum = sum + a[i];
        
    }
    printf("%d\n", sum);

    for (int i = 0; i < 10; i++)
    {
        psum += *(p+i);
    
    }
    printf("%d\n", psum);
}


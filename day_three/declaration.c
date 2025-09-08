#include <stdio.h>
#include <math.h>
int main()
{
    int i = 8, j = 5;
    float x = 0.005, y = 0.01;
    char c = 'c', d = 'd';
    int first = (3 * i * j) % (2 * d);
    printf("%d\n", first);
    float second = (i * j) % (c + 2 * d) / (x * y);
    printf("%f\n", second);
    int third = 5 * (i + j) > 'c';
    printf("%d\n", third);
    float fourth = 2 * x + (y == 0);
    printf("%f\n", fourth);
    float fifth = (x > y) && (i > 0) || (j < 5);
    printf("%f", fifth);
}
#include <stdio.h>

void add(int *a, int *b)
{
    int sum;
    sum = *a + *b;
    printf("%d", sum);
}

void sub(int *a, int *b)
{
    int sub;
    sub = *a - *b;
    printf("%d", sub);
}

void mul(int *a, int *b)
{
    int mul;
    mul = *a * *b;
    printf("%d", mul);
}

void div(int *a, int *b)
{
    float div;
    div = (float)*a / *b;
    printf("%f", div);
}

int main()
{
    int a, b, w;
    int *ptr = &w;
    printf("enter any two numbers\n");
    scanf("%d %d", &a, &b);
    printf("enter 1 for sum\n");
    printf("enter 2 for sub\n");
    printf("enter 3 for mul\n");
    printf("enter 4 for div\n");
    scanf("%d", &w);

    switch (*ptr)
    {
    case 1:
        add(&a, &b);
        break;

    case 2:
        sub(&a, &b);
        break;

    case 3:
        mul(&a, &b);
        break;
    case 4:
        div(&a, &b);
        break;
    default:
        break;
    }
}

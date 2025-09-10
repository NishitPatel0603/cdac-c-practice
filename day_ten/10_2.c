#include <stdio.h>
typedef struct complex_number
{
    float real;
    float img;
}com;

int main()
{
    com a;
    printf("enter the real and img of 1\n ");
    scanf("%f %f",&a.real,&a.img);
    com b;
    printf("enter the real and img of 2\n ");
    scanf("%f %f",&b.real,&b.img);

    printf("The sum of two complex number is %.02f + %.02fi \n", a.real + b.real, a.img + b.img);

}
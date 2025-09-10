#include <stdio.h>
#include <string.h>
// struct result
// {
//     float cpi;
//     float cgpa;
// };
struct student
{
    int roll;
    char name[20];
    // struct result re;
};
int main()
{
    struct student s[5];
    struct student *ptr = s;
    for (int i = 0; i < 2; i++)
    {
        scanf("%d %s", &ptr->roll, ptr->name); //&ptr->re.cpi, &ptr->re.cgpa
        ptr++;
    }

    for (int i = 0; i < 2; i++)
    {
        printf("roll no is %d\n name is %s\n ", s[i].roll, s[i].name); // s[i].re.cpi, s[i].re.cgpa
    }
} // cpi is %.2f\n cgpa is %.2f\n
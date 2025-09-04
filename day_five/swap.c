#include <stdio.h>

int swap(int a, int c)
{
    int b = 0;
    b = c;
    c = a;
    a = b;
    printf("%d %d", a,c);
}

int main()
{
    swap(5, 2);
}

/*#include <stdio.h>

int main()
{
    int a = 12;
    int b = 13;                                                                                     

    a = a + b;
    b = a - b;
    a = a - b;
    printf("swap is done %d and %d", a,b);

    return 0;
}

#include <stdio.h>                                            //swapping without extra variables                                       

int main()
{
    int a = 12;
    int b = 13;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("swap is done %d and %d", a, b);
    return 0;
}*/
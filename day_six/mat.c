#include <stdio.h>

int main()
{
    int i, j, k;
    int a[3][3];
    int b[3][3];
    int c[3][3];         
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]=0;
            for(k=0;k<3;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("The product of the two matrices is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

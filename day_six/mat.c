#include <stdio.h>

int main()
{
    int i = 0, j = 0, k = 0, l = 0;
    int a[3][3];
    int b[3][3];
    int c[3][3];             // 3x3 matrix
    for (i = 0; i <= 2; i++) // changed to 2 iterations
    {
        for (j = 0; j <= 2; j++) // changed to 2 iterations
        {
            scanf("%d", &a[i][j]); // reading int is safe with scanf
        }
    }
    for (k = 0; k <= 2; k++) // changed to 2 iterations
    {
        for (l = 0; l <= 2; l++) // changed to 2 iterations
        {
            scanf("%d", &b[k][l]); // reading int is safe with scanf
        }
    }
    for (i = 0; i <= 2; i++) // changed to 2 iterations
    {
        for (j = 0; j <= 2; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 0; i <= 2; i++) // changed to 2 iterations
    {
        for (j = 0; j <= 2; j++)
        {
            c[i][j] += a[i][k] * b[k][j];
        }
    }
    for (i = 0; i <= 2; i++) // changed to 2 iterations
    {
        for (j = 0; j <= 2; j++) // changed to 2 iterations
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n"); // new line after each row
    }
    return 0;
}

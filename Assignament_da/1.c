#include <stdio.h>
#include <stdlib.h>

int sum_of(int m, int n, int arr[m][n])
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                sum = sum + arr[i][j];
            }
            
        }
    }
    printf("%d\n",sum);

}
int main()
{
    int i, j, k;
    int m, n;

    printf("enter the valu of m x n :");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("emter the valu if arr[%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    sum_of(m, n, arr);
}
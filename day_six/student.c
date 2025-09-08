#include <stdio.h>

int main()
{
    int i, j, lar;
    int a[10][4];
    printf("Enter the student marks:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Enter marks for student %d subject %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("the student marks are:\n");
    printf("student no.|subject 1|subject 2|subject 3|subject 4\n");
    for (i = 0; i < 2; i++)
    {
        printf("   %d\t", i);
        for (j = 0; j < 4; j++)
        {
            printf("     %d    ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nHighest marks in each subject:\n");
    for (i = 0; i < 4; i++)
    {
        lar = a[0][i];
        for (int j = 1; j < 2; j++)
        {
            if (lar < a[j][i])
            {
                lar = a[j][i];
            }
        }
        printf("the higher number is %d\n", lar);
    }
}
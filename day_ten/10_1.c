#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    char gender;
    float exam_score;
};
int main()

{
    int i;
    struct student s[5];
    struct student *ptr = s;
    do
    {
        printf("Enter the mode you want to \n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            for (int i = 0; i < 2; i++)
            {
                scanf("%d %s %c %f", &ptr->roll, ptr->name, &ptr->gender, &ptr->exam_score);
                ptr++;
            }
            break;
        case 2:
            for (int i = 0; i < 2; i++)
            {
                printf("roll no is %d\nname is %s\ngender is %c\nexam score = %.02f \n", s[i].roll, s[i].name, s[i].gender, s[i].exam_score); // s[i].re.cpi, s[i].re.cgpa
            }
            break;
        case 3:
            float max = s[0].exam_score;
            for (int i = 0; i < 2; i++)
            {
                if (max < s[i].exam_score)
                {
                    max = s[i].exam_score;
                }
            }
            printf("The max marks are%.02f \n", max);
            break;
        case 4:
            float min = s[0].exam_score;
            for (int i = 0; i < 2; i++)
            {
                if (min > s[i].exam_score)
                {
                    min = s[i].exam_score;
                }
            }
            printf("The min marks are%.02f \n", min);
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (i != 5);
}
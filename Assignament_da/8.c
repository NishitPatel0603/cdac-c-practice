#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void insert_beg(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}


int delete_first()
{
    int x = -1;
    struct node *temp;
    if (start == NULL)
    {
        printf("List Is Empty\n");
    }
    else
    {
        temp = start;
        x = temp->data;
        start = start->next;
        free(temp);
        temp = NULL;
    }
    return x;
}

void traval_forward()
{
    struct node *cur;
    cur = start;
    if (start == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%d \t", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main()
{
    int num;

    while (num != 0)
    {
        
        printf("0. EXIT\n");
        printf("1. Enter the element in stack :\n");
        printf("2. Delete the element in stack :\n");
        printf("3. display\n");
        printf("enetr a optino :");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            int num1;
            printf("Enter the value you want to add in the stack :");
            scanf("%d",&num1);
            insert_beg(num1);
            break;          

        case 2:
            delete_first();
            break;

        case 3:
            traval_forward();
            break;

        default:
            printf("Enter a valid option you enter wrong option");
            break;
        }
    }
}


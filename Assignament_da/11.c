#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *priv;
};
struct node *start = NULL;

void insert_last(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->priv = NULL;
    struct node *cur;
    cur = start;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->priv = cur;
    }
}

void traval_forward()
{
    struct node *cur;
    cur = start;
    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%d\t", cur->data);
            cur = cur->next;
        }
    }
    printf("\n");
}


int delete_end()
{
    struct node *temp, *cur;
    int x = -1;
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        if (start->next == NULL)
        {
            temp = start;
            x = temp->data;
            start = NULL;
            free(temp);
            temp = NULL;
        }
        else
        {
            cur = start;
            while (cur->next->next != NULL)
            {
                cur = cur->next;
            }
            temp = cur->next;
            x = temp->data;
            cur->next = NULL;
            free(temp);
            temp = NULL;
        }
    }
}


int main()
{
    int num;

    while (num != 0)
    {
        
        printf("0. EXIT\n");
        printf("1. Enter the element in Deque :\n");
        printf("2. Delete the element in Deque :\n");
        printf("3. display\n");
        printf("enetr a optino :");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            int num1;
            printf("Enter the value you want to add in the Deque :");
            scanf("%d",&num1);
            insert_last(num1);
            break;          

        case 2:
            delete_end();
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
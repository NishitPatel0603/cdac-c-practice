#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

int searching(int s)
{
    struct node *cur;
    int count = 0;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        cur = start;
        while (cur != NULL && cur->data != s)
        {
            cur = cur->next;
            count++;
        }
        return count;
    }
    
}

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

void inseart_end(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    struct node *cur = start;
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
    }
}

void inseart_after(int n, int s)
{
    struct node *temp, *cur;
    if (start == NULL)
    {
        printf("List Is Empty\n");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        struct node *cur = start;
        while (cur != NULL && cur->data != s)
        {
            cur = cur->next;
        }
        if (cur != NULL)
        {
            temp->next = cur->next;
            cur->next = temp;
        }
        else
        {
            printf("Element Not Found\n");
        }
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

int delete_last()
{
    int x = -1;
    if (start == NULL)
    {
        printf("List Is Empty\n");
    }
    else
    {
        struct node *temp, *cur;
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
    return x;
}

void insert_befor(int n, int s)
{
    struct node *temp, *cur;
    if (start == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        if (start->data == s)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            cur = start;
            while (cur->next != NULL && cur->next->data != s)
            {
                cur = cur->next;
            }
            if (cur->next != NULL)
            {
                temp->next = cur->next;
                cur->next = temp;
            }
            else
            {
                printf("Element not found\n");
            }
        }
    }
}

void delete_spec(int s)
{
    struct node *temp, *cur;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if (start->data == s)
        {
            temp = start;
            start = temp->next;
            free(temp);
            temp = NULL;
        }
        else
        {
            cur = start;
            while (cur->next != NULL && cur->next->data != s)
            {
                cur = cur->next;
            }
            if (cur->next != NULL)
            {
                temp = cur->next;
                cur->next = temp->next;
                free(temp);
                temp = NULL;
            }
            else
            {
                printf("element note found\n");
            }
        }
    }
}

void revrsec()
{
    struct node *temp, *rev;
    while (start != NULL)
    {
        temp = start;
        start = temp->next;
        temp->next = rev;
        rev = temp;
    }
    start = rev;
}

void fun_print(struct node *cur)
{
    if (cur->next != NULL)
        fun_print(cur->next);
    printf("%d\t", cur->data);
}


void travel_back()
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        fun_print(start);
    }   
}

int main()
{
    int num;

    while (num != 11)
    {
        printf("1. incert beg\n");
        printf("2. incert last\n");
        printf("3. incert after\n");
        printf("4. incert befor\n");
        printf("5. delete first\n");
        printf("6. delete last\n");
        printf("7. delete_spec\n");
        printf("8. travel back\n");
        printf("9. reversec\n");
        printf("10. display\n");
        printf("11. searching\n");
        printf("12. EXIT\n");
        printf("enetr a optino :");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            int num1;
            printf("enter data you want to enter");
            scanf("%d", &num1);
            insert_beg(num1);
            break;

        case 2:
            int num2;
            printf("enter data you want to enter");
            scanf("%d", &num2);
            inseart_end(num2);
            break;

        case 3:
            int num3, num4;
            printf("enter data you want to enter and after which data");
            scanf("%d %d", &num3, &num4);
            inseart_after(num3, num4);
            break;

        case 4:
            int num5, num6;
            printf("enter data you want to enter and after which data");
            scanf("%d %d", &num5, &num6);
            insert_befor(num5, num6);
            break;


        case 5:
            int num7 = delete_first();
            printf("The element is deleted %d\n", num7);
            break;

        case 6:
            int num8 = delete_last();
            printf("The element is deleted %d\n", num8);
            break;

        case 7:
            int n;
            printf("enter the number you want to delete :");
            scanf("%d",&n);
            delete_spec(n);
            break;

        case 8: travel_back();break;

        case 9: revrsec();break;

        case 10:
            traval_forward();
            break;

        case 11:
            int num9;
            scanf("%d",&num9);
            printf("number is at the %d place\n",searching(num9));
        
        case 12:
            break;

        default:
            break;
        }
    }
}


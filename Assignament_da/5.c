#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *priv;
};
struct node *start = NULL;

void insert_begin(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->priv = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start->priv = temp;
        start = temp;
    }
}

void traval_forward()
{
    struct node *cur;
    cur = start;
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%d\t", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
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
            x = start->data;
            temp = start;
            start = NULL;
            insert_begin(x);
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
            insert_begin(x);
            free(temp);
            temp = NULL;
        }
    }
    return x;
}

void delete_spec(int s)
{
    struct node *temp, *cur;
    int x = -1;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if (start->data == s)
        {
            x = start->data;
            temp = start;
            start = temp->next;
            if (start != NULL)
                start->priv = NULL;
            insert_begin(x);
            free(temp);
            temp = NULL;
        }
        else
        {
            cur = start;
            while (cur != NULL && cur->data != s)
            {
                cur = cur->next;
            }
            if (cur != NULL)
            {
                if (cur->priv != NULL)
                    cur->priv->next = cur->next;
                if (cur->next != NULL)
                    cur->next->priv = cur->priv;
                x = cur->data;
                insert_begin(x);
                free(cur);
                cur = NULL;
            }
            else
            {
                printf("Element %d not found\n", s);
            }
        }
    }
}

int main()
{
    int num = -1, num1 = -1;

    while (1)
    {
        printf("Enter The Element (0 to stop): ");
        scanf("%d", &num);
        if (num == 0)
            break;
        insert_begin(num);
    }
    printf("\n");
    traval_forward();

    while (1)
    {
        printf("Enter The Element you want to find (0 to stop): ");
        scanf("%d", &num1);
        if (num1 == 0)
            break;
        delete_spec(num1);
        traval_forward();
    }
    return 0;
}

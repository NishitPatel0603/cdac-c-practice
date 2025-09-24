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

void insert_befor(int n, int s)
{
    struct node *temp, *cur;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->priv = NULL;
    cur = start;

    if (start == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        if (start->data == s)
        {
            temp->next = start;
            cur->priv = temp;
            start = temp;
        }
        else
        {
            while (cur->next != NULL && cur->next->data != s)
            {
                cur = cur->next;
            }
            if (cur->next != NULL)
            {
                temp->next = cur->next;
                temp->priv = cur;
                cur->next->priv = temp;
                cur->next = temp;
            }
            else
            {
                printf("element not found");
            }
        }
    }
}

void insert_after(int n, int s)
{
    struct node *temp, *cur;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->priv = NULL;
    cur = start;

    if (start == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        if (start->data == s)
        {
            temp->priv = start;
            temp->next = start->next;
            cur->next->priv = temp;
            cur->next = temp;
        }
        else
        {
            while (cur->next != NULL && cur->data != s)
            {
                cur = cur->next;
            }
            if (cur->next == NULL && cur->data == s)
            {
                insert_last(n);
            }
            else if (cur->next != NULL && cur->data == s)
            {
                temp->priv = cur;
                temp->next = cur->next;
                cur->next->priv = temp;
                cur->next = temp;
            }
            else
            {
                printf("element not found");
            }
        }
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
}

void traval_back()
{
    struct node *cur;
    cur = start;
    if (start == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        while (cur->priv != NULL)
        {
            printf("%d\t", cur->data);
            cur = cur->priv;
        }
        printf("%d", cur->data);
    }
}

int delete_first()
{
    struct node *temp;
    int x = -1;
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        temp = start;
        if (temp->next != NULL)
        {
            x = temp->data;
            start = temp->next;
            start->priv = NULL;
        }
        else
        {
            x = temp->data;
            start = NULL;
        }
        free(temp);
        temp = NULL;
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
            while (cur->next != NULL && cur->data != s)
            {
                cur = cur->next;
            }
            if (cur->next != NULL)
            {
                cur->priv->next = cur->next;
                cur->next->priv = cur->priv;
                free(cur);
                cur = NULL;
            }
            else if (cur->next == NULL && cur->data == s)
            {
                delete_end();
            }
        }
    }
}

void delete_befor(int s)
{
    struct node *cur, *temp;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if (start->data == s)
        {
            delete_first();
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
                cur->priv->next = cur->next;
                cur->next->priv = cur->priv;
            }
        }
    }
    free(cur);
    cur = NULL;
}

void delete_after(int s)
{
    struct node *cur, *temp;
    if (start == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        if (start->data == s)
        {
            temp = start;
            temp = temp->next;
            temp->priv->next = temp->next;
            temp->next->priv = temp->priv;
            free(temp);
            temp = NULL;
        }
        else
        {
            cur = start;
            while (cur->next != NULL && cur->data != s)
            {
                cur = cur->next;
            }
            if (cur->next->next == NULL)
            {
                cur->next = NULL;
            }            
            else if (cur->next != NULL)
            {
                cur = cur->next;
                cur->priv->next = cur->next;
                cur->next->priv = cur->priv;
                free(cur);
                cur = NULL;
            }
            else
            {
                printf("element not found");
            }
            
        }
    }
}

int main()
{
    insert_begin(10);
    insert_last(20);
    insert_last(30);
    insert_befor(15, 20);
    insert_after(1, 30);
    // delete_first();
    // delete_end();
     delete_spec(1);
    // delete_befor(30);
    // delete_after(30);
    traval_forward();
    printf("\n");
    // traval_back();
}
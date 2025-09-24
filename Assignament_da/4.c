#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *list1 = NULL;
struct node *list2 = NULL;
struct node *list3 = NULL;

void inseart_end_list1(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    struct node *cur = list1;
    if (list1 == NULL)
    {
        list1 = temp;
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

void inseart_end_list2(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    struct node *cur = list2;
    if (list2 == NULL)
    {
        list2 = temp;
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
void inseart_end_list3(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    struct node *cur = list3;
    if (list3 == NULL)
    {
        list3 = temp;
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

void traval_forward()
{
    struct node *cur;
    cur = list3;
    if (list3 == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("\n");
        while (cur != NULL)
        {
            printf("%d \t", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

void sort()
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            inseart_end_list3(list1->data);
            list1 = list1->next;    
        }
        else
        {
            inseart_end_list3(list2->data);
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        inseart_end_list3(list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        inseart_end_list3(list2->data);
        list2 = list2->next;
    }
}

int main()
{
    int num1, num2, num;
    printf("Enter The Number You Want To Add Element :");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter Element %d :", i);
        scanf("%d", &num1);
        inseart_end_list1(num1);
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter Element %d :", i);
        scanf("%d", &num2);
        inseart_end_list2(num2);
    }
    sort();
    traval_forward();
}
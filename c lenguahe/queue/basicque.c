#include <stdio.h>
#include <stdlib.h>
struct basicque
{
    int frount;
    int rear;
    int size;
    int *que;
};
struct basicque bq;


int underflow()
{
    if (bq.frount == -1 && bq.rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int overflow()
{
    if (bq.rear == bq.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(int value)
{
    if (overflow())
    {
        printf("que is full");
    }
    if (bq.frount == -1 && bq.rear == -1)
    {
        bq.frount = 0;
    }
    bq.que[++bq.rear] = value;
}
int deque()
{
    int tem = 0;
    if (underflow())
    {
        printf("que is Empty");
    }
    else
    {
        if (bq.frount == bq.rear)
        {
            bq.frount = -1;
            bq.rear = -1;
        }
        else
        {
            return tem = bq.que[bq.frount++];
        }
    }
}
void display()
{
    if (underflow())
    {
        printf("que is empty");
    }
    for (int i = bq.frount; i <= bq.rear; i++)
    {
        printf("%d\t", bq.que[i]);
    }
    printf("\n");
}

int main()
{
    bq.frount = -1;
    bq.rear = -1;
    bq.size = 100;
    bq.que = (int *)malloc(bq.size * sizeof(int));

    enque(9);
    enque(10);
    enque(11);
    enque(6);
    enque(8);
    enque(2);
    display();

    deque();
    deque();
    deque();
    display();
}
#include <stdio.h>
#include <stdlib.h>

#define size 5

int frount = -1;
int rear = -1;
int que[size];

int underflow()
{
    if (frount == -1 && rear == -1)
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
    if ((rear + 1) % size == frount)
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
        printf("que is full\n");
        return;
    }
    if (frount == -1 && rear == -1)
    {
        frount = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    que[rear] = value;
}
int deque()
{
    int tem = 0;
    if (underflow())
    {
        printf("que is Emptyn\n");
        return -1;
    }
    else
    {
        tem = que[frount];
        if (frount == rear)
        {
            frount = -1;
            rear = -1;
        }
        else
        {
            frount = (frount + 1) % size;
        }
        return tem;
    }
}
void display()
{
    if (underflow())
    {
        printf("queue is empty\n");
        return;
    }

    int i = frount;  
    printf("Queue elements: ");
    while (1)
    {
        printf("%d\t", que[i]);
        if (i == rear)  
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}


int main()
{

    enque(9);
    enque(10);
    enque(11);
    enque(6);
    enque(8);
    display();

    deque();
    deque();
    deque();
    display();

    enque(9);
    enque(10);
    enque(11);
    enque(6);
    display();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct basicque
{
    int frount;
    int rear;
    int size;
    int *que;
};
struct basicque cq;


int underflow()
{
    if (cq.frount == -1 && cq.rear == -1)
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
    if ((cq.rear + 1) % cq.size == cq.frount) 
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
    if (cq.frount == -1 && cq.rear == -1)
    {
        cq.frount = 0;
        cq.rear = 0; 
    }
    else
    {
        cq.rear = (cq.rear + 1) % cq.size; 
    }
    cq.que[cq.rear] = value; 
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
        tem = cq.que[cq.frount]; 
        if (cq.frount == cq.rear)
        {
            cq.frount = -1;
            cq.rear = -1;
        }
        else
        {
            cq.frount=(cq.frount+1) %cq.size;
        }
        return tem; 
    }
}
void display()
{
    if (underflow())
    {
        printf("que is empty\n");
        return; 
    }
    
    int i = cq.frount;
    printf("Queue elements: ");
    while (1) 
    {
        printf("%d\t", cq.que[i]);
        if (i == cq.rear) 
            break; 
        i = (i + 1) % cq.size;
    }
    printf("\n");
}

int main()
{
    cq.frount = -1;
    cq.rear = -1;
    cq.size = 5;
    cq.que = (int *)malloc(cq.size * sizeof(int));

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

    free(cq.que); 
    return 0;
}
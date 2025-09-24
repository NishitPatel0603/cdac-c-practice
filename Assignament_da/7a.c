#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main()
{
    char ch[100];
    int flag = 1;
    printf("enetr brecs :");
    scanf("%s", &ch);

    for (int i = 0; i < strlen(ch); i++)
    {

        switch (ch[i])
        {
        case '(':
        {
            push(ch[i]);
            break;
        }
        case '[':
        {
            push(ch[i]);
            break;
        }
        case '{':
        {
            push(ch[i]);
            break;
        }

        case ')':
        {
            if (isEmpty() || peek() != '(' && stack[top] == '(')
            {
                flag = 0;
            }
            else
                pop();
            break;
        }
        case ']':
        {
            if (isEmpty() || peek() != '[' && stack[top] == '[')
            {
                flag = 0;            
            }
            else
                pop();
            break;
        }
        case '}':
        {
            if (isEmpty() || peek() != '{' && stack[top] == '{')
            {
                flag = 0;
            }
            else
                pop();
            break;
        }

        default:
            break;
        }
    }
    if (flag && isEmpty())
    {
        printf("it is balance\n");
    }
    else
    {
        printf("it is not balance\n");
    }

    return 0;
}
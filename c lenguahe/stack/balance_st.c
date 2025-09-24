#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stek
{
    int top;
    int size;
    char *s;
};
struct stek s1;

int isEmpty()
{
    if (s1.top == -1)
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
    if (s1.top == s1.size - 1)
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
    s1.s[++s1.top] = value;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s1.s[s1.top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s1.s[s1.top];
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s1.top; i++)
    {
        printf("%c ", s1.s[i]);
    }
    printf("\n");
}

int main()
{
    int MAX;
    printf("enter the number which size you want :");
    scanf("%d ",&MAX);
    
    s1.top = -1;
    s1.size = MAX;
    s1.s = (char *)malloc(MAX * sizeof(char));
    
    if (s1.s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

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
            if (isEmpty() || peek() != '(' && s1.s[s1.top] == '(')
            {
                flag = 0;
            }
            else
                pop();
            break;
        }
        case ']':
        {
            if (isEmpty() || peek() != '[' && s1.s[s1.top] == '[')
            {
                flag = 0;            
            }
            else
                pop();
            break;
        }
        case '}':
        {
            if (isEmpty() || peek() != '{' && s1.s[s1.top] == '{')
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
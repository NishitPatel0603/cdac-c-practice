#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct infic
{
    int top;
    int size;
    char *s;
};
struct infic in;

// struct infic1
// {
//     int top;
//     int size;
//     int *s;
// };
// struct infic1 in1;

int prec(char);
int isFull();
int isEmpty();
char pop();
char peek();
void display();
void push(char);

// int prec1(char);
// int isFull1();
// int isEmpty1();
// int pop1();
// int peek1();
// void display1();
// void push1(char);

int main()
{
    char input[100];
    char output[100];
    int j = 0;

    in.top = -1;
    in.size = 100;
    in.s = (char *)malloc(in.size * sizeof(char));

    if (in.s == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter expression: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];

        if (isdigit(ch) || isalpha(ch))
        {
            output[j++] = ch;
        }
        else
        {
            switch (ch)
            {
            case '(':
            case '[':
            case '{':
                push(ch);
                break;

            case ')':
                while (!isEmpty() && peek() != '(')
                {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '(')
                {
                    pop();
                }
                break;

            case ']':
                while (!isEmpty() && peek() != '[')
                {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '[')
                {
                    pop();
                }
                break;

            case '}':
                while (!isEmpty() && peek() != '{')
                {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '{')
                {
                    pop();
                }
                break;

            case '*':
            case '/':
            case '+':
            case '-':
                while (!isEmpty() && prec(peek()) >= prec(ch))
                {
                    output[j++] = pop();
                }
                push(ch);
                break;

            default:
                break;
            }
        }
    }

    while (!isEmpty())
    {
        output[j++] = pop();
    }
    output[j] = '\0';

    printf("Postfix expression: %s\n", output);
    // free(in.s);

    int a, b, c;
    // in.top = -1;
    // in.size = 100;
    // in.s = (int *)malloc(in.size * sizeof(int));

    if (in.s == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < strlen(output); i++)
    {
        char ch = output[i];
    
        switch (ch)
        {
        case '*':
        {
            a = pop() - '0';
            b = pop() - '0';
            push(b*a + '0');
            break;
        }
        case '/':
        {
            a = pop() - '0';
            b = pop() - '0';
            push(a / b + '0');
            break;
        }
        case '+':
        {
            a = pop() - '0';
            b = pop() - '0';
            push(a + b + '0');
            break;
        }
        case '-':
        {
            a = pop() - '0';
            b = pop() - '0';
            push(a - b + '0');
            break;
        }

        default:
            push(ch-'0');
            break;
        }
    }
    printf("%d\n", (peek() + '0'));

    free(in.s);
    return 0;
}

int isEmpty()
{
    if (in.top == -1)
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
    if (in.top == in.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    in.s[++in.top] = value;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return in.s[in.top--];
}

char peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return in.s[in.top];
}

int prec(char c)
{
    switch (c)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
    case '[':
    case '{':
        return 1;
    default:
        return 0;
    }
}

// int isEmpty1()
// {
//     if (in1.top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull1()
// {
//     if (in1.top == in1.size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void push1(char value)
// {
//     if (isFull1())
//     {
//         printf("Stack Overflow\n");
//         return;
//     }
//     in1.s[++in1.top] = value;
// }

// int pop1()
// {
//     if (isEmpty1())
//     {
//         printf("Stack Underflow\n");
//         return '\0';
//     }
//     return in1.s[in1.top--];
// }

// int peek1()
// {
//     if (isEmpty1())
//     {
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return in1.s[in1.top];
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
char stack[MAX];

int top1 = -1;
int stack1[MAX];

int prec(char);
int isFull();
int isEmpty();
char pop();
char peek();
void push(char);

int isFull1();
int isEmpty1();
void push1(int value);
int pop1();
int peek1();

int main()
{
    char input[MAX];
    char output[MAX];
    int j = 0;

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
                    output[j++] = pop();
                if (!isEmpty() && peek() == '(')
                    pop();
                break;
            case ']':
                while (!isEmpty() && peek() != '[')
                    output[j++] = pop();
                if (!isEmpty() && peek() == '[')
                    pop();
                break;
            case '}':
                while (!isEmpty() && peek() != '{')
                    output[j++] = pop();
                if (!isEmpty() && peek() == '{')
                    pop();
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                while (!isEmpty() && prec(peek()) >= prec(ch))
                    output[j++] = pop();
                push(ch);
                break;
            default:
                break;
            }
        }
    }
    while (!isEmpty())
        output[j++] = pop();
    output[j] = '\0';

    printf("Postfix expression: %s\n", output);

    for (int i = 0; i < strlen(output); i++)
    {
        char ch = output[i];
        if (isdigit(ch))
        {
            push1(ch - '0');
        }
        else
        {
            int a = pop1();
            int b = pop1();
            int c;
            switch (ch)
            {
            case '+':
                c = b + a;
                break;
            case '-':
                c = b - a;
                break;
            case '*':
                c = b * a;
                break;
            case '/':
                c = b / a;
                break;
            }
            push1(c);
        }
    }
    printf("Result: %d\n", peek1());

    return 0;
}

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX - 1;
}
void push(char value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}
char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}
char peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack[top];
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

int isEmpty1()
{
    return top1 == -1;
}
int isFull1()
{
    return top1 == MAX - 1;
}
void push1(int value)
{
    if (isFull1())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack1[++top1] = value;
}
int pop1()
{
    if (isEmpty1())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack1[top1--];
}
int peek1()
{
    if (isEmpty1())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack1[top1];
}

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

int prec(char);
int isFull();
int isEmpty();
char pop();
char peek();
void display();
void push(char);

int main()
{
    char input[100];
    char output[100];
    int j = 0;
    
    in.top = -1;
    in.size = 100;
    in.s = (char *)malloc(in.size * sizeof(char));
    
    if (in.s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter expression: ");
    scanf("%s", input);
    
    for(int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];
        
        if (isdigit(ch) || isalpha(ch)) {
            output[j++] = ch;
        }
        else {
            switch (ch)
            {
            case '(':
            case '[':
            case '{':
                push(ch);
                break;
                
            case ')':
                while (!isEmpty() && peek() != '(') {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '(') {
                    pop(); 
                }
                break;
                
            case ']':
                while (!isEmpty() && peek() != '[') {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '[') {
                    pop(); 
                }
                break;
                
            case '}':
                while (!isEmpty() && peek() != '{') {
                    output[j++] = pop();
                }
                if (!isEmpty() && peek() == '{') {
                    pop(); 
                }
                break;
                
            case '*':
            case '/':
            case '+':
            case '-':
                while (!isEmpty() && prec(peek()) >= prec(ch)) {
                    output[j++] = pop();
                }
                push(ch);
                break;
                
            default:
                break;
            }
        }
    }
    
    while (!isEmpty()) {
        output[j++] = pop();
    }
    output[j] = '\0'; 
    
    printf("Postfix expression: %s\n", output);
    
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

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= in.top; i++)
    {
        printf("%c ", in.s[i]);
    }
    printf("\n");
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
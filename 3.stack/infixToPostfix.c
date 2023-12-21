
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct
{
    char items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    return s->items[s->top];
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Operator precedence
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// Infix to postfix conversion
void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    s.top = -1;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(')
            {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                pop(&s);
            }
        }
        else
        {
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(peek(&s)))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isOperator(infix[i])) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}') {
            while (top >= 0 && stack[top] != '(' && stack[top] != '[' && stack[top] != '{') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && (stack[top] == '(' || stack[top] == '[' || stack[top] == '{')) {
                top--;
            }
        } else {
            postfix[j++] = infix[i];
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

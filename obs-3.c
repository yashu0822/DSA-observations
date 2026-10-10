#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if (top >= MAX - 1)
    {
        printf("Error: Stack Overflow!\n");
        return;
    }
    stack[++top] = c;

}
char pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}
char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];
        if (!isOperator(c) && c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}')
        {
            postfix[j++] = c;
        }
        else if (isOperator(c))
        {
            if (top == -1 || precedence(peek()) < precedence(c) || peek() == '(')
            {
                push(c);
            }
            else
            {
                while (top != -1 && peek() != '(' && precedence(peek()) >= precedence(c))
                {
                    postfix[j++] = pop();
                }
                push(c);
            }
        }

        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1)
            {
                pop(); // Remove the '('
            }
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (formula): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x)
{
    stack[++top] = x;
}

// Pop operation
char pop()
{
    return stack[top--];
}

// Check precedence
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If '(' push to stack
        else if (ch == '(')
        {
            push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }

        // If operator
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
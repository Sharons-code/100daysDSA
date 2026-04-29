#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Push
void push(Node **top, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow (Invalid Expression)\n");
        exit(1);
    }
    Node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Check operator
int isOperator(char *token)
{
    return (strlen(token) == 1 &&
            (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

// Evaluate postfix
int evaluatePostfix(char *expr)
{
    Node *stack = NULL;

    char *token = strtok(expr, " ");

    while (token != NULL)
    {

        // Operand
        if (!isOperator(token))
        {
            push(&stack, atoi(token));
        }
        // Operator
        else
        {
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            switch (token[0])
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    printf("Division by zero error\n");
                    exit(1);
                }
                res = a / b;
                break;
            }
            push(&stack, res);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main()
{
    char expr[100];

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = 0;

    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);

    return 0;
}
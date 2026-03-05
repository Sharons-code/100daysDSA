#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d\n", stack[top]);
        top--;
    }
}

// Display operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements (top to bottom): ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, op, value, i;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter operation (1 Push, 2 Pop, 3 Display): ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if (op == 2)
        {
            pop();
        }
        else if (op == 3)
        {
            display();
        }
        else
        {
            printf("Invalid operation\n");
        }
    }

    return 0;
}
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
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
    }
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
    }
}

// Display stack
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Remaining stack elements (top to bottom): ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    int n, m, i, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        pop();
    }

    display();

    return 0;
}
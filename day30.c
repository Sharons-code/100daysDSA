#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *head = NULL;

// Function to insert a new term
void insert(int c, int e)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to display polynomial
void display()
{
    struct node *temp;
    temp = head;

    printf("\nPolynomial = ");

    while (temp != NULL)
    {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    int n, c, e, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter coefficient of term %d: ", i);
        scanf("%d", &c);

        printf("Enter exponent of term %d: ", i);
        scanf("%d", &e);

        insert(c, e);
    }

    display();

    return 0;
}
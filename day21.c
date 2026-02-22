#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        // Allocate memory
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List:\n");

    // Traverse and print
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
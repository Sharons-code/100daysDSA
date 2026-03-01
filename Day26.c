#include <stdio.h>
#include <stdlib.h>

// Define structure of doubly linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create doubly linked list
struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

// Function to traverse and print list in forward direction
void displayForward(struct Node *head)
{
    struct Node *temp = head;

    printf("\nDoubly Linked List (Forward Traversal): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createList(n);

    displayForward(head);

    return 0;
}
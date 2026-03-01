#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node
{
    int data;
    struct Node *next;
};

// Function to create circular linked list
struct Node *createCircularList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

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

    // Make it circular
    if (temp != NULL)
    {
        temp->next = head;
    }

    return head;
}

// Function to traverse circular linked list
void display(struct Node *head)
{

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("\nCircular Linked List elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of the circular linked list:\n");
    struct Node *head = createCircularList(n);

    display(head);

    return 0;
}
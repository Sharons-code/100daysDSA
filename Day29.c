#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes
struct Node *createList(int n);
int getLength(struct Node *head);
struct Node *rotateRight(struct Node *head, int k);
void display(struct Node *head);

// Create linked list
struct Node *createList(int n)
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
    return head;
}

// Get length of linked list
int getLength(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate linked list right by k places
struct Node *rotateRight(struct Node *head, int k)
{

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = getLength(head);

    k = k % n; // Important if k > n

    if (k == 0)
        return head;

    struct Node *temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make list circular
    temp->next = head;

    // Move to (n-k)th node
    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++)
        temp = temp->next;

    // New head
    struct Node *newHead = temp->next;

    // Break the circle
    temp->next = NULL;

    return newHead;
}

// Display linked list
void display(struct Node *head)
{
    printf("\nLinked List after rotation: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{

    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of the linked list:\n");
    struct Node *head = createList(n);

    printf("\nEnter value of k (number of rotations): ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}
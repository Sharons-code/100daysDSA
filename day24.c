#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create linked list
struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++)
    {
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

// Function to delete first occurrence of key
struct Node *deleteKey(struct Node *head, int key)
{
    struct Node *temp = head, *prev = NULL;

    // If head node holds the key
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
    {
        printf("Key not found in the list.\n");
        return head;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display function
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    struct Node *head = createList(n);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);

    printf("Linked List after deletion:\n");
    display(head);

    return 0;
}
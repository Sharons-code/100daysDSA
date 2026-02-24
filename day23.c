#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node
{
    int data;
    struct Node *next;
};

// Create Linked List
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

// Merge Two Sorted Lists
struct Node *mergeLists(struct Node *head1, struct Node *head2)
{
    struct Node *merged = NULL, *temp = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (head1->data <= head2->data)
        {
            newNode->data = head1->data;
            head1 = head1->next;
        }
        else
        {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        if (merged == NULL)
        {
            merged = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Remaining elements of first list
    while (head1 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = head1->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        head1 = head1->next;
    }

    // Remaining elements of second list
    while (head2 != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = head2->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        head2 = head2->next;
    }

    return merged;
}

// Display List
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
    int n, m;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first sorted list:\n");
    struct Node *head1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second sorted list:\n");
    struct Node *head2 = createList(m);

    struct Node *merged = mergeLists(head1, head2);

    printf("Merged Sorted List:\n");
    display(merged);

    return 0;
}
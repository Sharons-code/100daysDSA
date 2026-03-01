#include <stdio.h>
#include <stdlib.h>

// 1️⃣ Structure Definition
struct Node
{
    int data;
    struct Node *next;
};

// 2️⃣ Function Prototypes
struct Node *createList(int n);
int getLength(struct Node *head);
void findIntersection(struct Node *head1, struct Node *head2);

// 3️⃣ Create Linked List
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

// 4️⃣ Get Length
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

// 5️⃣ Find Intersection (Memory Based)
void findIntersection(struct Node *head1, struct Node *head2)
{

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    if (len1 > len2)
        diff = len1 - len2;
    else
        diff = len2 - len1;

    // Move pointer of longer list
    if (len1 > len2)
    {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    }
    else
    {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Compare addresses (real intersection)
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            printf("\nIntersection Node Value: %d\n", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("\n0\n");
}

// 6️⃣ Main Function
int main()
{

    int n, m;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d", &n);
    printf("Enter elements of first linked list:\n");
    struct Node *head1 = createList(n);

    printf("\nEnter number of nodes in second linked list: ");
    scanf("%d", &m);
    printf("Enter elements of second linked list:\n");
    struct Node *head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}
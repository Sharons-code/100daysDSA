#include <stdio.h>

int main()
{
    int n, i, pos, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100]; // Extra space for insertion

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Check valid position
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to right
    for (i = n - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert element
    arr[pos - 1] = x;

    n++; // Increase size

    // Print updated array
    printf("Updated array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
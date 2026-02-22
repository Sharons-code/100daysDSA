#include <stdio.h>

int main()
{
    int n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100]; // Extra safe size

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);

    // Check valid position
    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to left
    for (i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--; // Reduce size

    // Print updated array
    printf("Updated array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
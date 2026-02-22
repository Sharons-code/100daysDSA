#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (n == 0)
    {
        return 0;
    }

    int j = 0; // pointer for unique elements

    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Unique elements:\n");
    for (i = 0; i <= j; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
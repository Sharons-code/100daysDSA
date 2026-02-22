#include <stdio.h>

int main()
{
    int p, q, i, j, k;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int arr1[100];
    printf("Enter %d sorted arrival times:\n", p);
    for (i = 0; i < p; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int arr2[100];
    printf("Enter %d sorted arrival times:\n", q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int merged[200]; // Enough space for p + q

    i = 0; // pointer for arr1
    j = 0; // pointer for arr2
    k = 0; // pointer for merged array

    // Merge process
    while (i < p && j < q)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1
    while (i < p)
    {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2
    while (j < q)
    {
        merged[k++] = arr2[j++];
    }

    printf("Merged chronological log:\n");
    for (i = 0; i < p + q; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}
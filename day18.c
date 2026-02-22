#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100], result[100];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n; // Important if k > n

    for (int i = 0; i < n; i++)
    {
        result[(i + k) % n] = arr[i];
    }

    printf("Rotated Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}
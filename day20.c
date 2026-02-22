#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefix_sum = 0;

    // Large enough to handle prefix range safely
    int freq[2001] = {0};
    int offset = 1000; // To handle negative prefix sums

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];

        if (prefix_sum == 0)
            count++;

        if (freq[prefix_sum + offset] > 0)
            count += freq[prefix_sum + offset];

        freq[prefix_sum + offset]++;
    }

    printf("Count of zero sum subarrays: %d\n", count);

    return 0;
}
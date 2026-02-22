#include <stdio.h>

int main()
{
    int r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[100][100];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    printf("Spiral Order: ");

    while (top <= bottom && left <= right)
    {

        // Left → Right
        for (int i = left; i <= right; i++)
            printf("%d ", A[top][i]);
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", A[i][right]);
        right--;

        // Right → Left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                printf("%d ", A[bottom][i]);
            bottom--;
        }

        // Bottom → Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                printf("%d ", A[i][left]);
            left++;
        }
    }

    return 0;
}

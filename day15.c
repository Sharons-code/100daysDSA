#include <stdio.h>

int main()
{
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[100][100];
    int sum = 0;

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Add primary diagonal elements
    for (int i = 0; i < m && i < n; i++)
    {
        sum += A[i][i];
    }

    printf("Primary Diagonal Sum = %d\n", sum);

    return 0;
}
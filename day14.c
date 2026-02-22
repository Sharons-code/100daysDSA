#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of matrix (n): ");
    scanf("%d", &n);

    int A[100][100];
    int flag = 1;

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                if (A[i][j] != 1)
                    flag = 0;
            }
            else
            {
                if (A[i][j] != 0)
                    flag = 0;
            }
        }
    }

    if (flag == 1)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
#include <stdio.h>

int main()
{
    int m, n;
    int A[10][10];
    int i, j;
    int flag = 1;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    if (m != n)
    {
        flag = 0;
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (A[i][j] != A[j][i])
                {
                    flag = 0;
                }
            }
        }
    }

    if (flag == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
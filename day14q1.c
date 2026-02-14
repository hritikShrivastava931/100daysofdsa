#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int i;
    int j;
    int flag = 1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 1)
                {
                    flag = 0;
                }
            }
            else
            {
                if(matrix[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }

    if(flag == 1)
    {
        printf("Identity Matrix");
    }
    else
    {
        printf("Not an Identity Matrix");
    }

    return 0;
}
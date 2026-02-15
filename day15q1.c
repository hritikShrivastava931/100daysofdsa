#include <stdio.h>

int main()
{
    int m;
    int n;
    
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    int i;
    int j;
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    int limit;
    
    if(m < n)
    {
        limit = m;
    }
    else
    {
        limit = n;
    }
    
    for(i = 0; i < limit; i++)
    {
        sum = sum + matrix[i][i];
    }
    
    printf("%d", sum);
    
    return 0;
}
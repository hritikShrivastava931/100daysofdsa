#include <stdio.h>

int main()
{
    int n;
    int m;

    scanf("%d", &n);
    scanf("%d", &m);

    int adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    int type;

    printf("Enter 0 for undirected, 1 for directed: ");
    scanf("%d", &type);

    int u;
    int v;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(type == 0)
        {
            adj[v][u] = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }

    return 0;
}
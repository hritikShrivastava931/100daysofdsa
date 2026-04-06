#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

int dfs(int node, int parent)
{
    visited[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[node][i] == 1)
        {
            if(visited[i] == 0)
            {
                if(dfs(i, node))
                {
                    return 1;
                }
            }
            else if(i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int hasCycle()
{
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(i, -1))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int edges;
    int u;
    int v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");

    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if(hasCycle())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
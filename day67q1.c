#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void dfs(int v)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }

    printf("Topological ordering:\n");

    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}
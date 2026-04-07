#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

bool dfs(int node)
{
    visited[node] = true;
    recStack[node] = true;

    for(int i = 0; i < V; i++)
    {
        if(graph[node][i])
        {
            if(!visited[i] && dfs(i))
            {
                return true;
            }
            else if(recStack[i])
            {
                return true;
            }
        }
    }

    recStack[node] = false;

    return false;
}

bool detectCycle()
{
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for(int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if(detectCycle())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX;
    int min_index = -1;

    for(int i = 0; i < n; i++)
    {
        if(mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

int primMST(int graph[MAX][MAX], int n)
{
    int key[MAX];
    int mstSet[MAX];

    for(int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;

    int totalWeight = 0;

    for(int count = 0; count < n; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        totalWeight += key[u];

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST(graph, n);

    printf("%d\n", result);

    return 0;
}
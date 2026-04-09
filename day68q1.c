#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}

int main()
{
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while(!isEmpty())
    {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1)
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }

    if(count != n)
    {
        printf("\nCycle detected! Topological sorting not possible.\n");
    }

    return 0;
}
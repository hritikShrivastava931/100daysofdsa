#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        int value = queue[front];
        front++;
        return value;
    }
}

int isEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    enqueue(source);
    visited[source] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
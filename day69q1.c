#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    int weight;
    struct Node* next;
}Node;

Node* adj[MAX];

typedef struct MinHeapNode
{
    int vertex;
    int dist;
}MinHeapNode;

typedef struct MinHeap
{
    int size;
    MinHeapNode heap[MAX];
}MinHeap;

void swap(MinHeapNode* a, MinHeapNode* b)
{
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* h, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if(smallest != i)
    {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

MinHeapNode extractMin(MinHeap* h)
{
    MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insertHeap(MinHeap* h, int vertex, int dist)
{
    int i = h->size;
    h->heap[i].vertex = vertex;
    h->heap[i].dist = dist;
    h->size++;

    while(i && h->heap[i].dist < h->heap[(i-1)/2].dist)
    {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

Node* createNode(int v, int w)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w)
{
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(int V, int src)
{
    int dist[MAX];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while(h.size > 0)
    {
        MinHeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        Node* temp = adj[u];

        while(temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if(dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Vertex   Distance from Source\n");

    for(int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main()
{
    int V = 5;

    for(int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0,1,10);
    addEdge(0,4,5);
    addEdge(1,2,1);
    addEdge(4,1,3);
    addEdge(4,2,9);
    addEdge(2,3,4);
    addEdge(3,0,7);
    addEdge(3,2,6);

    dijkstra(V, 0);

    return 0;
}
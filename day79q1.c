#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1005
#define MAXM 100005
#define INF INT_MAX

// Adjacency list structures
int head[MAXN], nxt[MAXM*2], to[MAXM*2], wt[MAXM*2], cnt;
int dist[MAXN], visited[MAXN];
int n, m;

// Min-heap (priority queue) structures
typedef struct {
    int dist, node;
} HeapNode;

HeapNode heap[MAXM*2];
int heap_size = 0;

void add_edge(int u, int v, int w) {
    cnt++;
    to[cnt] = v;
    wt[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void push(int d, int node) {
    heap_size++;
    heap[heap_size].dist = d;
    heap[heap_size].node = node;
    // Bubble up
    int i = heap_size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        HeapNode tmp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = tmp;
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heap_size--];
    // Bubble down
    int i = 1;
    while (1) {
        int smallest = i;
        if (2*i <= heap_size && heap[2*i].dist < heap[smallest].dist)
            smallest = 2*i;
        if (2*i+1 <= heap_size && heap[2*i+1].dist < heap[smallest].dist)
            smallest = 2*i+1;
        if (smallest == i) break;
        HeapNode tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

void dijkstra(int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    push(0, src);

    while (heap_size > 0) {
        HeapNode cur = pop();
        int u = cur.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int e = head[u]; e != 0; e = nxt[e]) {
            int v = to[e], w = wt[e];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(dist[v], v);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w); // undirected graph
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF");
        else
            printf("%d", dist[i]);
        if (i < n) printf(" ");
    }
    printf("\n");

    return 0;
}
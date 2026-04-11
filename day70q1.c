#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

struct Edge
{
    int u;
    int v;
    int w;
};

int main()
{
    int n;
    int m;
    scanf("%d %d",&n,&m);

    struct Edge edges[m];

    int i;

    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }

    int source;
    scanf("%d",&source);

    int dist[n+1];

    for(i=1;i<=n;i++)
    {
        dist[i]=INF;
    }

    dist[source]=0;

    int j;

    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;

            if(dist[u]!=INF && dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }

    for(j=0;j<m;j++)
    {
        int u=edges[j].u;
        int v=edges[j].v;
        int w=edges[j].w;

        if(dist[u]!=INF && dist[u]+w<dist[v])
        {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for(i=1;i<=n;i++)
    {
        if(dist[i]==INF)
        {
            printf("INF ");
        }
        else
        {
            printf("%d ",dist[i]);
        }
    }

    printf("\n");

    return 0;
}
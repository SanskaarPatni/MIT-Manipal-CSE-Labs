#include<stdio.h>
#include<stdlib.h>
int G[20][20],q[20],visited[20],front = -1, rear = -1 ,E,V;
void bfs(int v)
{
    visited[v] = 1;
    q[++rear]=v;
    front=0;
    while(front<=rear)
    {
        int n=q[front++];
        printf("%d ",n );

        for(int i=0;i<V;i++)
        {
            if(G[n][i]==1 && visited[i]==0)
            {   
                visited[i]=1;
                q[++rear]=i;
            }
        }

    }
 }
int main()
{
    int i,j,v1,v2;
    int v;
    printf("\t\t\tGraphs\n");
    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            G[i][j]=0;
    }
    for(i=0;i<V;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;
    }
    printf("\n********ADJACENCY MATRIX*********\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    bfs(v);

return 0;
}
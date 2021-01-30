#include <stdio.h>
#include <stdlib.h>
int source,V,E,visited[20],G[20][20],color[20],flag=0;
void bipartite(int i)
{
    int j;
    
    
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1)
        {
            if(visited[j]==0)
            {
                visited[j]=1;
                if(color[i]==1)
                {
                    color[j]=2;
                }
                else{
                    color[j]=1;
                }
                bipartite(j);
            }
            else if(color[i]==color[j])
            {
                flag=1;
                return;

            }
            
        }
            
    }
}
int main()
{
    int i,j,v1,v2;
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
    for(j=0;j<V;j++)
            color[i]=0;
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
    printf("\nEnter the source: ");
    scanf("%d",&source);
    visited[source]=1;
    color[source]=1;
    bipartite(source);
    if(flag)
    {
        printf("Graph is not bipartite\n");
    }
    else
    {
        printf("Graph is bipartite\n");
    }
    return 0;
}
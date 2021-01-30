#include <stdio.h>
#include <stdlib.h>
int V,E,visited[20],G[20][20];
int arr[100];
int top=0;
void DFS(int i)
{
    int j;
    visited[i]=1;
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1&&visited[j]==0){
            DFS(j);
            
    }
    
}
arr[top++]=i;
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
    for(i=0;i<V;i++)
    {
        visited[i]=0;
    }
   
    printf("Traversal Order: ");
   for(i=0;i<V;i++)
   {
    if(visited[i]==0)
    {
         DFS(i);
    }
   }
   
    for(int p=V-1;p>=0;p--)
    {
        printf("%d ",arr[p]);
    }
   
    return 0;
}
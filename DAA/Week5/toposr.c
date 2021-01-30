#include <stdio.h>
#include <stdlib.h>
int V,E,G[20][20],indegree[20],queue[20];
int arr[20];
int front=-1;int rear=-1;
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
    for(i=0;i<20;i++)
    {
        indegree[i]=0;
    }
    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;
        indegree[v2]++;
    }
    printf("Indegere order\n");
    for(j=0;j<V;j++)
            printf(" %d ",indegree[j]);
    printf("\n********ADJACENCY MATRIX*********\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
   
    for(i=0;i<V;i++)
    {
    if(indegree[i]==0)
    {
    	queue[++rear]=i;
        front=0;
     }
	}

    int count=0;
    int p=0;
    while(rear>=front)
    { 
    	int g=queue[front];
       	arr[p++]=queue[front++];
    	for(int f=0;f<V;f++)
    	{
    		if(G[g][f]==1)
    		{
    			if(--indegree[f]==0)
    			{
    			queue[++rear]=f;
    			}
    		}
    	}
    	count++;
    }
    for(p=0;p<V;p++)
    {
    	printf("%d ",arr[p]);
    }   
    return 0;
}
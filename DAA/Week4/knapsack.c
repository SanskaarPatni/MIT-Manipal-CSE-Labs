#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int Knapsack(int *w,int *v,int n,int B)
{
	int i,temp;
	int maxVal=0,maxSeq=0;
	int totalWeight=0,totalValue=0;
	int opcount=0;
	int index=0;
	for(i=1;i<pow(2,n);i++)
	{
		totalWeight=0;
		totalValue=0;
		for(int j=0;j<=n;j++)
		{
			if(i & (1<<j))
			{
				totalWeight=totalWeight+w[j];
				totalValue=totalValue+v[j];
			}
		}
		if(totalWeight<=B && totalValue>maxVal)
		{
			
			maxVal=totalValue;
			printf("%d ",maxVal);
			maxSeq=i;
		}
	}
	//printf("%d",maxSeq);
	return maxSeq;
}

int main()
{
	int *v,*w,i,n,knaps,B;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	v=(int*)calloc(n,sizeof(int));
	w=(int*)calloc(n,sizeof(int));
	printf("Please eneter the weights:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("Please enter the values:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	printf("Enter the KnapSack capacity:\n");
	scanf("%d",&B);
	knaps=Knapsack(w,v,n,B);
	printf("Knapsack contains the following items\n");
	i=0;
	for(int j=0;j<n;j++)
	{
		if(knaps & 1<<j)
		{
			printf("item %d value %d\n",j,v[j]);
		}
	}

	return 0;
}
#include<stdio.h>
#include<stdlib.h>
int row=0;
int arr[100][100];
void put(int a[],int n)
{
    int i;
    int *ar=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
        arr[row][i]=a[i];
}
void permutations(int a[],int size,int n)
{
    int i,t;
    if(size==1)
    {
        put(a,n);
        row++;
        return;
    }
    for(i=0;i<size;i++)
    {
        permutations(a,size-1,n);
        if(size%2==1)
        {
            t=a[0];
            a[0]=a[size-1];
            a[size-1]=t;
        }
        else
        {
            t=a[i];
            a[i]=a[size-1];
            a[size-1]=t;   
        }
    }
}
int main()
{
    int n,i,j;
    printf("Input the value of N: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Input the Job-Assignment Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int fact=1;
    int permu[n];
    for(i=2;i<=n;i++)
    {
        fact=fact*i;
    }
    int sum[fact];
    for(i=0;i<n;i++)
    {
        permu[i]=i;
    }
    permutations(permu,n,n);
    for(i=0;i<fact;i++)
    sum[i]=0;
    printf("All Possible Combinations of Cost: ");
    for(i=0;i<fact;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i]=sum[i]+a[j][arr[i][j]];
        }
    }
    for(i=0;i<fact;i++)
    {
        printf("%d ",sum[i]);
    }
    printf("\n");
    int min=sum[0];
    int pos=0;
    for(i=1;i<fact;i++)
        if(min>sum[i])
        {
            pos=i;
            min=sum[i];
        }
    printf("Best Job Assignment:\n");
    for(i=0;i<n;i++)
    {
        printf("JOB: %d --> Person: %d\n",(i+1),(arr[pos][i]+1));
    }
    printf("Minimum Cost: %d\n",min);
    return 0;
}
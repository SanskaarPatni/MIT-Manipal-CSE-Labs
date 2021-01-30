#include<stdio.h>
int add(int a[],int N){
int sum=0;
for(int i=0;i<N;i++){
  sum=sum+a[i];
}
return sum;
}

int main()
{
	int n,a[100];
	printf("Enter the value for n:\n");
	scanf("%d",&n);
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    int sum=add(a,n);
    printf("Sum of elemets of array is %d \n",sum);
    return 0;

}
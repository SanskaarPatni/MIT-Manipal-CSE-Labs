#include<stdio.h>
#include<stdlib.h>
int add(int *a,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum + *(a+i);
	}
	return sum;
}
int main(){
	printf("Enter number of elements of the array:\n");
	int n;
	scanf("%d",&n);
	int* a=(int *)calloc(n,sizeof(int));
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++){
    	scanf("%d",a+i);
    }
    int sum=add(a,n);
    printf("Sum of elements of the array is %d\n",sum);
    return 0;


}
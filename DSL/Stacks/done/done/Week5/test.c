#include<stdio.h>
#include<stdlib.h>
void NoOfOccurences(int a[],int n,int num,int *t){
	
	for(int i=0;i<n;i++){
	if(*(a+i)==num){
		*t=*t+1;
		}
	}
	
}
int main(){
	printf("Enter number of elements in array\n");
	int n;
	scanf("%d",&n);
	int *a=(int *)calloc(n,sizeof(int));
	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	printf("Inputed array is:\n");
	for(int i=0;i<n;i++){
		printf("%d\n",*(a+i));
	}
	printf("Enter a number whose occurences has to be 		found out:");
	int key;
	scanf("%d",&key);
	int t=0;
	NoOfOccurences(a,n,key,&t);

	printf("Number of occurences of the number %d is %d",key,t);

	return 0;
}

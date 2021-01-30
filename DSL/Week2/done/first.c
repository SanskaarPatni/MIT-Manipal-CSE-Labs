#include<stdio.h>
#include<stdlib.h>
void reverse(int *a,int n){
	int temp;
	for(int i=0;i<n/2;i++){
         temp=*(a+i);
         *(a+i)=*(a+n-1-i);
         *(a+n-1-i)=temp;
	}
	
    for(int i=0;i<n;i++){
    	printf("%d  ",*(a+i));
    }
   
 }
int main(){
	int n;
	printf("ENter the value for n: \n");
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	printf("Enter elements of the array:\n");
    for(int i=0;i<n;i++){
    	scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
    	printf("%d  ",*(a+i));
    }
    reverse(&a[0],n);
}
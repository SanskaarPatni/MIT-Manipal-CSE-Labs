#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Enter number of elements of the array:\n");
	int n;
	int i=0;
	scanf("%d",&n);
	int* a=(int *)calloc(n,sizeof(int));
    printf("Enter the elements of the array");
    for(i=0;i<n;i++){
    	scanf("%d",(a+i));
    }
    printf("Forward");
      for(i=0;i<n;i++){
    	printf("%d",*(a++));
    }
    printf("Backward");
//dont miss out on these
    
a=a-1;
    for(i=0;i<n;i++){
    	printf("%d",*(a--));
    }

    return 0;


}

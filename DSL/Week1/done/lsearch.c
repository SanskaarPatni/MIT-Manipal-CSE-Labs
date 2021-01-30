#include<stdio.h>
#include<stdlib.h>
void Lsearch(int *a,int N,int key){
for(int i=0;i<N;i++){
  if(a[i]==key){
  	printf("Element is at %dth position",i+1);

  }
  }

}

int main()
{
	int n,key;
	printf("Enter the value for n:\n");
	scanf("%d",&n);
	int* a=(int *)calloc(10,sizeof(int));
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++){
       scanf("%d",(a+i));
    }
    printf("Enter the number to be found:\n");
    scanf("%d",&key);
    Lsearch(a,n,key);
    return 0;

}

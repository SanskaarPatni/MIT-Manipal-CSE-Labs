#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
int * a=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++){
		printf("%d\n",*(a+i));
		printf("%d\n",i );
		i++;
	}
}
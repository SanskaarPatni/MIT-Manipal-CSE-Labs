#include<stdlib.h>
#include<stdio.h>
int main(){
	int *a=(int *)calloc(5,sizeof(int));
	for(int i=0;i<5;i++)
	{
		printf("%d ",*(a+i));
	}
	return 0;
}
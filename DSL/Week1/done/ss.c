#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int i,int j){
	int temp;
	temp=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=temp;
return;
}
int main(){
	int n;
	scanf("%d",&n);
	int *b=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	int in=0;
	int min=b[0];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(*(b+j)<min){
				in=j;
			}
		}
	sort(b,in,i);
	}
	for(int i=0;i<n;i++)
	printf("%d\n",*(b+i));
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct A1{
	int *a;
	float *b;
};
int main(){
	struct A1 *x;
  	x=(struct A1*)malloc(sizeof(struct A1));
  	int c=0;
  	x->a=&c;
  	int n;
  	scanf("%d",&n);
  	x=(struct A1*)realloc(x,n*sizeof(struct A1));
  	int f=100;
  	(x+1)->a=&f;
  	printf("%d",*((x+1)->a));
free(x);

}

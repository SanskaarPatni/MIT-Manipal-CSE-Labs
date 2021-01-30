#include<stdio.h>
#include<stdlib.h>
int* ptrA(int *a,int *b){
	printf("Value of a and b are %d and %d\n", *a,*b);
	int divide=(*a)/(*b);
	int *s=&divide;
	return s;
}
int main(){
	int *a=(int*)calloc(1,sizeof(int));
	printf("Enter the value for a:\n");
    scanf("%d",a);
    printf("Enter the value for b:\n");
    int *b=(int*)malloc(sizeof(int));
    scanf("%d",b);
    int **f=(int**)malloc(sizeof(int*));
    /*printf("%d\n",a);
    printf("%p\n",&a);
    printf("%p\n",a);
    printf("%d\n",*a);
    b=a;
    printf("%p",b);*/
    *f=ptrA(a,b);
    printf("Value after dividing is %d\n",**f );
    return 0;
}
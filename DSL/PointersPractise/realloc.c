#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a;
	a=(int *)malloc(5*sizeof(int));
	for(int i=0;i<5;i++){
	scanf("%d\n",(a+i));
}
	for(int i=0;i<5;i++){
	printf("%d\n",*(a+i));
}
int *ptr=(int *)realloc(a,10*sizeof(int));
//free(a);
printf("\n");
for(int i=5;i<10;i++){
	scanf("%d",(ptr+i));
	
}
for(int i=0;i<10;i++){

printf("%d\n",*(ptr+i));

}
if(!a){
	for(int i=0;i<4;i++){
	printf("%d\n",*(a+i));
}
}
}

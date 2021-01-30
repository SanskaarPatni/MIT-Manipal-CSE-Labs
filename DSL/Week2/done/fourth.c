#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
	int roll;
	char name[20];
}St;
void read(St *p)
{
	printf("Enter roll\n");
	scanf("%d",&(p->roll));
	printf("Enter name\n");
	scanf("%s",p->name);
}
void display(St *p)
{
	printf("Roll no and Name of Student is %d and %s\n",(p->roll),p->name);
}
void sort(St a[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j].roll<a[min].roll){
				min=j;

			}

		}
		if(min!=i)
		{
			swap(&a[i],&a[min]);
		}
	}
}
void swap(St *a,St *b)
{
	St c=*a;
	*a=*b;
	*b=c;
}
int main(){
	printf("Enter number of Students");
	int n;
	scanf("%d",&n);
	St * a=(St*)calloc(n,sizeof(St));
	for(int i=0;i<n;i++){
		read(a+i);
	}
	for(int i=0;i<n;i++){
		display(a+i);
	}
	sort(a,n);
for(int i=0;i<n;i++){
		display(a+i);
	}
}

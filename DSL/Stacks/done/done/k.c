#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
	int data[MAX];
	int top;
}stack; 
int empty(stack *s)
{
if(s->top==-1)
return(1);
return(0);
}
int full(stack *s)
{
if(s->top==MAX-1)
return(1);
return(0);
}
void push(stack *s,int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop(stack *s)
{
int x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}
int main(){
	stack s;
	int n,k;
	s.top=-1;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	printf("Enter number k:\n");
	scanf("%d",&k);
	printf("Enter elements:\n");
  int count=0;
	int * a=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	int flag=0;
	int i=0;
	for(i=0;i<n;i++){
		if(s.top==-1){
			push(&s,a[0]);
			continue;
		}
		if(flag==0){
		if(s.data[s.top]<*(a+i)){
			while(s.data[s.top]<*(a+i) || s.top!=-1)
			{
				int t=pop(&s);
				count++;
				if(count==k){
					flag=1;
				break;
			}
		}
			push(&s,*(a+i));
		}
		else{
			push(&s,*(a+i));
		}
	}
	if(flag==1)
	{
		break;
	}
}
	for(int k=i+1;k<n;k++){
		push(&s,*(a+k));
	}
	printf("\n________\n");
	for(int i=0;i<=(s.top);i++)
	printf("%d\n",s.data[i]);
}
#include<stdlib.h>
#include<stdio.h>
typedef struct{
	int top;
	int *arr;
}stack;
void push(stack *s,int ele)
{
	s->arr[++s->top]=ele;
}
int pop(stack *s)
{
	return s->arr[s->top--];
}
void display(stack *s)
{
	for(int i=0;i<=s->top;i++)
	{
		printf("%d ",s->arr[i]);
	}
}
int main()
{
	int n;
	printf("Enter number of elements in the stack\n");
	scanf("%d",&n);
	stack s;
	s.top=-1;
	s.arr=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		push(&s,1);
	}
	int t=pop(&s);
	printf("%d\n",t);
	display(&s);

}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int data[100];
	int top;
}stack;

void push(stack *s,int data)
{
	s->data[++s->top]=data;
}
int pop(stack *s)
{
	int m;
	m=s->data[s->top--];
	return m;
}

int isEmpty(stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else return 0;
}
int main()
{
	printf("Enter an array of size 5 elements\n");
	int a[5];
	int b[5];
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	stack s;
	s.top=-1;
	for(int i=4;i>=0;i--)
	{
		if(s.top==-1)
		{
			b[i]=-1;
			push(&s,a[i]);
		}
		else 
		{
			//if(s.data[s.top]<a[i])
			//{
			while(s.data[s.top]<a[i] && s.top!=-1)
			{
				int t=pop(&s);
			}
			if(s.top==-1)
			{
				b[i]=-1;
			}
			else{
				b[i]=s.data[s.top];
			}
			push(&s,a[i]);
			}
			//else{
			//	b[i]=s.data[s.top];
			//	push(&s,a[i]);
			//}

			//}
}
for(int i=0;i<5;i++)
{
	printf("%d\t",a[i]);
}
printf("\n");
for(int i=0;i<5;i++)
{
	printf("%d\t",b[i]);
}
printf("\n");
}

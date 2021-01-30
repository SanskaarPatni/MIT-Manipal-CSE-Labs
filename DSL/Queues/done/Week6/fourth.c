#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct
{
char data[MAX];
int top;	
}stack;
void init(stack *s)
{
s->top=-1;
}
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
char pop(stack *s)
{
char x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}
int main(){
	stack s1,s2;
	init(&s1);
	init(&s2);
	printf("Performing first in first out operation using two stacks!\n");
	char k='3';
	while(k=='1'||k=='2'||k=='3'){
		printf("1.Add\n2.Delete\n3.Display\n4.Exit\n");
		printf("Your choice\n");
        char p;
			scanf("%c",&k);
		if(k=='1'){
		printf("\nEnter element :\n");
		char n;
		char p;
		scanf("%c",&p);//for the newline character problem
		scanf("%c",&n);
		push(&s1,n);
		scanf("%c",&p);
		}
		else if(k=='2'){
		scanf("%c",&p);
		if(empty(&s2)){
			while(!empty(&s1)){
			push(&s2,pop(&s1));
			}
		}
		printf("Deleted element is %c\n",pop(&s2));
		
		}
		else if(k=='3'){
			printf("Elements in the queue are:\n");
		for(int i=0;i<=s2.top;i++){
			printf("%c\n",s2.data[i]);

		}
		if(!empty(&s1)){
		for(int i=s1.top;i>=0;i--){
			printf("%c\n",s1.data[i]);
		}
}

	scanf("%c",&p);}
		else{
			exit(0);
		}
	}
}

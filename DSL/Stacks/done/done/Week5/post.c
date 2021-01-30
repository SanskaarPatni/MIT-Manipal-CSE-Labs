#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 20
typedef struct 
{
int data[MAX];
int top;
}stack;
int evaluate(char x,int op1,int op2)
{
if(x=='+')
return(op2+op1);
if(x=='-')
return(op2-op1);
if(x=='*')
return(op2*op1);
if(x=='/')
return(op2/op1);
if(x=='%')
return(op2%op1);
if(x=='^' || x=='$')
	return (pow(op2,op1));
}
void strrev(char *ptr,int n){
	for(int i=0;i<n/2;i++){
		char temp;
        temp=*(ptr+i);  
		*(ptr+i)=*(ptr +n-i-1);
		*(ptr +n-i-1)=temp;
	}

}

int empty(stack *s)
{
if(s->top==-1)
return(1);
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

int main()
{
stack s;
char x;
char postfix[20];
int op1,op2,val;
s.top=-1;
scanf("%s",postfix);
int length=strlen(postfix);
//strrev(postfix,length);
//printf("%s",postfix);
int i=0;
for(int i=0;postfix[i]!='\0';i++)
{
	x=postfix[i];
	if(isdigit(x)){
	push(&s,x-'0');

}
/*x-‘0’ for removing the effect of ascii */
else 
{

op1=pop(&s);
op2=pop(&s);
int val=evaluate(x,op1,op2);
push(&s,val);
}
}
val=pop(&s);
printf("\nvalue of expression=%d",val);
return 0;
}

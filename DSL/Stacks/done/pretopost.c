#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct{
	char data[20][20];
	int top;
}stack;
void strrevv(char *str,int length)
{
	char temp;
	for(int i=0;i<length/2;i++)
	{
		temp=*(str+i);
		*(str+i)=*(str+length-i-1);
		*(str+length-i-1)=temp;
	}
}

int isOperator(char p)
{
	switch(p)
	{
		case '*':
		case '/':
		case '+':
		case '-':
		case '$':
		case '^':return 1;
		default:return 0;
	}
}
void push(stack *s,char a[])
{
	strcpy(s->data[++s->top],a);
}
char* pop(stack *s)
{
	return (s->data[s->top--]);
}
int main(){
	stack s;
	s.top=-1;
	printf("Enter a prefix expression");
	char pre[20];
	scanf("%s",pre);
	char post[20];
	strrevv(pre,strlen(pre));
	for(int i=0;pre[i]!='\0';i++)
	{
		char x=pre[i];
		if(isOperator(x))
		{
			char result[]={x,'\0'};
			char *op1=pop(&s);
			char *op2=pop(&s);
			strcat(op1,op2);
			strcat(op1,result);
			push(&s,op1);
		}
		else{
			char res[]={x,'\0'};
			push(&s,res);
		}
	}
	char *temp=pop(&s);
	printf("Postifix expression is \n%s",temp);
	return 0;



}
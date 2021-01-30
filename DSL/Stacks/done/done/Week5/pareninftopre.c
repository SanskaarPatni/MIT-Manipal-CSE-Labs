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
int pre(char symb){
	switch(symb)
	{
		case '#':return 0;
		case ')':return 1;
		case '+':return 2;
		case '-':return 2;
		case '*':return 3;
		case '/':return 3;
		case '$':return 4;
		case '^':return 4;
	}
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
int main(){
stack s;
char x;
char prefix[20];
char infix[20];
s.top=-1;
scanf("%s",infix);
int length=strlen(infix);
strrev(infix,length);
push(&s,'#');
int i=0;
int p=0;
for(int i=0;infix[i]!='\0';i++)
{
	x=infix[i];
    switch(x){
    	case ')':push(&s,')');
    	break;
    	case '(':while(s.data[s.top]!=')')
    	          prefix[p++]=pop(&s);
    	          int ele=pop(&s);
    	          break;
    	case '+':
    	case '-':
     	case '*':
    	case '/':while(pre(s.data[s.top])>pre(x))
    	            prefix[p++]=pop(&s);
    	            push(&s,x);
    	            break;
    	case '$':if(s.data[s.top]=='$')
                   prefix[p++]=pop(&s);
                   push(&s,'$');
                   break;	

        default: prefix[p++]=x;

    }
}
while(s.data[s.top]!='#'){
	prefix[p++]=pop(&s);
}
prefix[p]='\0';
strrev(infix,length);
strrev(prefix,p);
printf("Prefix equivalent of infix is %s  -->  %s",infix,prefix);
}
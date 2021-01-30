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
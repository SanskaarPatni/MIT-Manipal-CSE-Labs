#include <stdio.h>
#include <stdlib.h>
#define MAX 10
# define true 1
# define false 0
typedef struct{
  char item[MAX];
  int top;
}stack;
void push(stack *ps,char x)
{
    if(ps->top!=MAX -1)
    {
        ps->top++;
        ps->item[ps->top]=x;
    }
}
char pop(stack *ps)
{
    if(!empty(ps))
        return(ps->item[(ps->top--)]);
}
int empty(stack *ps)
{
    if(ps->top==-1)
        return true;
    else
        return false;
}
void main()
{
    char expn[25],c,d;
int i=0;
stack s;
s.top=-1;
printf("\n Enter the expression: ");
gets(expn);
while((c=expn[i++])!='\0')
{
    if(c=='(')
      push(&s,c);
    else
      if(c==')')
      {
        d=pop(&s);
        if(d!='(')
        {
           printf("\n Invalid Expression");
           break;
           }
           }
           }
if(empty(&s))
    printf("\n Balanced Expression");
else printf("\nNot  a balanced Expression");
}


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
    else return '#';
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
char expn[25],c;
int i=0;
stack s;
s.top=-1;
printf("\n Enter string: ");
scanf("%s",expn);
int l=strlen(expn);
printf("Length of the string is %d",l);
while((c=expn[i++])!='\0')
{
    push(&s,c);
}
printf("\n");
for(i=0;i<=s.top;i++)
{
printf("%c",s.item[i]);
}
for(i=0;i<l;i++){
    if(expn[i]!=pop(&s)){
    printf("\nNot a Palindrome");
    break;}
}
if(empty(&s))
    printf("\n Palindrome");
}

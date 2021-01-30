#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node *next;
}NODE;
NODE* push(NODE *top,int x)
{
NODE *new;
new=(NODE*)malloc(sizeof(struct node));
new->next=NULL;
new->info=x;

if(top==NULL){
	return new;
}
new->next=top;
top=new;
return(top);
}
NODE* pop(NODE *top)
{
NODE *temp;
if(top==NULL)
{
printf("\nStack Underflow\n");
return top;
}
temp=top;
printf("Deleted element is %d",temp->info);
free(temp);
top= top->next;
return(top);
}
NODE* deletedup(NODE* top)
{
	NODE *p1,*p2;
	p1=top;
	p2=top;
	while(p1!=NULL && p1->next!=NULL)
	{
		p2=p1;
		while(p2!=NULL && p2->next!=NULL){
			if(p1->info==p2->next->info){
				NODE* dup=p2->next;
				p2->next=p2->next->next;
				free(dup);
			}
			else{
				p2=p2->next;
			}
	}
	p1=p1->next;
}
return top;
}
void display(NODE *top)
{
NODE *temp;
printf("\nSTACK:\n");
if(top==NULL)
{
printf(" Stack is empty");
printf("\n\n**********************************************\n");
return;
}
temp=top;
while(temp!=NULL)
{
printf("%5d",temp->info);
temp=temp->next;
}
printf("\n\n**********************************************");
}
int getchoice()
{
int ch;
printf("**********************************************\n\n");
printf("--------------------Menu--------------------\n");
printf("1. Push\n2. Pop\n3. Display\n4. Exit\n5.Delete duplicates\n");
printf("Enter your choice:");
scanf("%d",&ch);
return(ch);
}

int main()
{
NODE *top;
int x,ch;
top=NULL;
while(1)
{
ch=getchoice();
switch(ch)
{
case 1: printf("Enter the element to be pushed:");
scanf("%d",&x);
top=push(top,x);
display(top);
break;
case 2:top=pop(top);
break;

case 3: display(top);
break;
case 4: exit(1);
case 5:top=deletedup(top);
break;
default: printf("\nInvalid choice");
printf("\n\n**********************************************");
}
}
return 0;
}
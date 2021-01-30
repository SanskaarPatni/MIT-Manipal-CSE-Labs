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
NODE* delete(NODE* top,int pos)
{
	NODE* curr=top;
	NODE* prev=NULL;
	for(int i=0;i<pos && curr!=NULL;i++){
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL){
			printf("position out of bounds\n");
		}
		else{
			prev->next=curr->next;
			free(curr);
		}
		return top;


} 
int getchoice()
{
int ch;
printf("**********************************************\n\n");
printf("--------------------Menu--------------------\n");
printf("1. Push\n2. Pop\n3. Display\n4. Exit\n5.\n");
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
case 5:printf("Insert posn?\n");
int pos;
scanf("%d",&pos);
top=delete(top,pos);
break;
default: printf("\nInvalid choice");
printf("\n\n**********************************************");
}
}
return 0;
}
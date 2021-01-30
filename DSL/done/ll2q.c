//double pointer necessary for queues since front and rear do values return karreha hai
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int info;
struct node *next;
}*NODE;
void insertrear(NODE *front ,NODE *rear,int x)
{
NODE new;
new=(NODE)malloc(sizeof(struct node));
new->next=NULL;
new->info=x;
if(*front==NULL){
	*front=*rear=new;
	return;
}
(*rear)->next=new;
(*rear)=(*rear)->next;
}
void deltefront(NODE *front,NODE *rear)
{
if(*front==NULL && *rear==NULL){
	printf("Queue is empty\n");
}
else if((*rear)->next==*front){
	printf("Queue is empty\n");
}
else{
NODE temp;
temp=(*front);
printf("Deleted element is %d",temp->info);
free(temp);
*(front)=(*front)->next;
}
}
void display(NODE front,NODE rear)
{
NODE temp;
printf("\nSTACK:\n");
if(front==NULL || rear->next==front)
{
printf("Stack is empty");
printf("\n\n**********************************************\n");
return;
}
while(front!=NULL)
{
printf("%5d",front->info);
front=front->next;
}
printf("\n\n**********************************************");
}
int getchoice()
{
int ch;
printf("**********************************************\n\n");
printf("--------------------Menu--------------------\n");
printf("1.InsertRear\n2.Delete Front\n3. Display\n4. Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
return(ch);
}

int main()
{
NODE front;
NODE rear;
int x,ch;
front=NULL;
rear=NULL;
while(1)
{
ch=getchoice();
switch(ch)
{
case 1: printf("Enter the element to be pushed:");
scanf("%d",&x);
insertrear(&front,&rear,x);
break;
case 2:deltefront(&front,&rear);
break;

case 3: display(front,rear);
break;
case 4: exit(1);
default: printf("\nInvalid choice");
printf("\n\n**********************************************");
}
}
return 0;
}
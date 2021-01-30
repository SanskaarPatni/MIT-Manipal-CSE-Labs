#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}*NODE;
NODE insert_rearcircular(NODE first,int ele){
	NODE n;
	n=(NODE)malloc(sizeof(struct node));
	n->data=ele;
	n->next=n;
	if(first==NULL){
		n->next=n;
		return n;
	}
	NODE t=first;
	while(t->next!=first){
		t=t->next;
	}
	n->next=first;
	t->next=n;
	return first;
}
void display(NODE first){
	if(first==NULL){
		printf("List is empty\n");
	}
	else if(first->next==first){
			printf("%d\t",first->data);
	}
    else{
    NODE new=first;
	while(new->next!=first){
		printf("%d\t",new->data);
		new=new->next;
	}
	printf("%d",new->data);
}
}
int main(){
	NODE l1=(NODE)malloc(sizeof(struct node));
	l1->next=l1;
	int t=1;
	while(t==1){
	printf("1.Enter an element\n0.Stop insertion in circular linked list\n");
	scanf("%d",&t);
	if(t==0){
		break;
	}
	printf("Enter the element to be inserted:\n");
	int ele;
	scanf("%d",&ele);
	l1=insert_rearcircular(l1,ele);
	}
	t=1;
	NODE l2=(NODE)malloc(sizeof(struct node));
	l2->next=l2;
	while(t==1){
	printf("1.Enter an element\n0.Stop insertion in circular linked list\n");
	scanf("%d",&t);
	if(t==0){
		break;
	}
	printf("Enter the element to be inserted:\n");
	int ele;
	scanf("%d",&ele);
	l2=insert_rearcircular(l2,ele);
	}
display(l1);
printf("\n");
display(l2);
NODE l3=NULL;
NODE h1=l1->next;
NODE h2=l2->next;
do{
	if(h1->data>h2->data){
		l3=insert_rearcircular(l3,h2->data);
		h2=h2->next;
	}
	else if(h1->data<h2->data){
		l3=insert_rearcircular(l3,h1->data);
		h1=h1->next;
	}
	else{
		l3=insert_rearcircular(l3,h1->data);
		h1=h1->next;
		h2=h2->next;
	}
}while(h1!=l1 && h2!=l2);
while(h1!=l1){
	l3=insert_rearcircular(l3,h1->data);
	h1=h1->next;
}
while(h2!=l2){
	l3=insert_rearcircular(l3,h2->data);
	h2=h2->next;
}
printf("\n");
display(l3);
}
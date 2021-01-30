#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char data[20];
	struct node *llink;
	struct node *rlink;
}*NODE;

NODE insertfrontDL(NODE first,char ele[]){
	NODE n=(NODE)malloc(sizeof(struct node));
	strcpy(n->data,ele);
	n->llink=NULL;
	n->rlink=NULL;
	if(first==NULL){
		return n;

	}
	n->rlink=first;
	first->llink=n;
	return n;
}
NODE insertrearDL(NODE first,char ele[]){
	NODE n=(NODE)malloc(sizeof(struct node));
	strcpy(n->data,ele);
	n->llink=NULL;
	n->rlink=NULL;
	if(first==NULL){
		return n;
	}
	NODE curr=first;
	while(curr->rlink!=NULL){
		curr=curr->rlink;
	}
	curr->rlink=n;
	n->llink=curr;
	return first;
}
NODE deleterearDL(NODE first){
	if(first==NULL){
		printf("List is empty");
		return first;
	}
	NODE curr=first;
	while(curr->rlink!=NULL){
		curr=curr->rlink;
	}
	curr->rlink=NULL;
	curr->llink->rlink=NULL;
	curr->llink=NULL;
	printf("Freed element is %s\n",curr->data);
	free(curr);
	return first;
}
NODE deletefrontDL(NODE first)
{
	NODE x;
	x=first;
	first=first->rlink;
	first->llink=NULL;
	printf("Freed element is %s\n",x->data);
	free(x);
	return first;
}
void display(NODE head){
	while(head!=NULL){
		printf("%s ",head->data);
		head=head->rlink;
	}
}
NODE reverseDLL(NODE first){
	NODE temp=NULL;
	NODE current=first;
	while(current!=NULL)
	{
		temp=current->llink;
		current->llink=current->rlink;
		current->rlink=temp;
		current=current->llink;
	}
	if(temp!=NULL){
		first=temp->llink;

	}
	return first;

}
int main(){
	NODE first=NULL;
	first=insertrearDL(first,"yo");
	first=insertrearDL(first,"hello");
	first=insertfrontDL(first,"bye");
	first=insertfrontDL(first,"no");
	first=insertrearDL(first,"please");
	display(first);
	first=deleterearDL(first);
	display(first);
	printf("\n");
	first=deletefrontDL(first);
	display(first);
	printf("\n");
	/*first=reverseDLL(first);
	display(first);*/
	first=reverseDLL(first);
	display(first);

}

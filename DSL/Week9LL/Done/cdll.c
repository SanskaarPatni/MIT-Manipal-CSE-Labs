#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *llink,*rlink;
}*NODE;
NODE insert_frontCDL(NODE first,int ele)
{
	NODE n=(NODE)malloc(sizeof(struct node));
	n->data=ele;
	n->rlink=n->llink=NULL;
	if(first==NULL){
		n->llink=n->rlink=n;
		return n;
	}
	n->llink=first->llink;
	n->rlink=first;
	first->llink->rlink=n;
	first->llink=n;
	return n;
}
NODE insert_rearCDL(NODE first,int ele){
	NODE n=(NODE)malloc(sizeof(struct node));
	n->data=ele;
	n->rlink=n->llink=NULL;
	if(first==NULL){
		n->llink=n->rlink=n;
		return n;
	}
	first->llink->rlink=n;
	n->llink=first->llink;
	first->llink=n;
	n->rlink=first;
	return first;
}
NODE delete_frontCDL(NODE first){
	if(first==NULL){
		printf("Linked List is Empty");
		return NULL;
	}
	if(first->llink==first){
		printf("Deleted element is %d\n",first->data);
		free(first);
		return NULL;
	}
	NODE del;
	del=first;
	first->llink->rlink=first->rlink;
	first->rlink->llink=first->llink;
	printf("Deleted element is %d\n",del->data);
	first=first->rlink;
	free(del);
	return first;
}

NODE delete_rearCDL(NODE first){
	if(first==NULL){
		printf("List is empty\n");
		return NULL;
	}
	if(first->llink==first){
		printf("Deleted element is %d\n",first->data);
		free(first);
		return NULL;
	}
	NODE del=first->llink;
	first->llink->llink->rlink=first;
	first->llink=first->llink->llink;
	printf("Deleted element is %d\n",del->data);
	free(del);
	return first;
}
void Display(NODE first){
	if(first==NULL){
		printf("Empty\n");
		return ;
	}
	NODE temp=first;
	while(temp->rlink!=first){
		printf("%d ",temp->data);
		temp=temp->rlink;
	}
	printf("%d",temp->data);
	printf("\n");
}
int main(){
	NODE first=NULL;
	first=insert_rearCDL(first,4);
	first=insert_frontCDL(first,3);
	first=insert_rearCDL(first,5);
	Display(first);
	first=delete_frontCDL(first);
	Display(first);
	first=delete_rearCDL(first);
	Display(first);
}
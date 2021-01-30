#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
} *NODE;
NODE insert_sort(NODE first,int ele){
	NODE n=(NODE)malloc(sizeof(struct node));
	n->data=ele;
	n->next=NULL;
	if(first==NULL)
		return n;
	if(ele<first->data){
		n->next=first;
		return n;
	}
	NODE prev,curr;
	curr=first;
	while(curr!=NULL && ele>curr->data)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=n;
	n->next=curr;
	return first;
}
void remove_node(NODE first)
{
	if(first==NULL){
		printf("List is empty\n  ");
		return;
	}
	NODE curr=first;
	NODE dup=NULL;
	while(curr!=NULL && curr->next!=NULL)
	{
		if(curr->data==curr->next->data)
		{
		dup=curr->next;
		curr->next=dup->next;
		free(dup);
	}
	else
	{
		curr=curr->next;
	}
}
}
NODE unionL1L2(NODE L1,NODE L2){
	NODE L3=NULL;
	if(L1==NULL && L2!=NULL){
		return L2;
	}
	if(L2==NULL && L1!=NULL){
		return L1;
	}
	if(L2==NULL && L1==NULL)
	{
		return L1;
	}
	while(L1!=NULL && L2!=NULL)
	{
		if(L1->data == L2->data){
			L3=insert_sort(L3,L1->data);
			L1=L1->next;
			L2=L2->next;
		}
		else if(L1->data>L2->data){
			L3=insert_sort(L3,L2->data);
			L2=L2->next;
		}
		else{
			L3=insert_sort(L3,L1->data);
			L1=L1->next;
		}

	}
	//aise hi karna
	while(L1!=NULL){
		L3=insert_sort(L3,L1->data);
		L1=L1->next;
	}
	while(L2!=NULL){
		L3=insert_sort(L3,L2->data);
		L2=L2->next;
	}
	return L3;
}
NODE interL1L2(NODE L1,NODE L2){
	NODE L4=NULL;
	if(L1==NULL || L2==NULL){
		return NULL;
	}
	while(L1!=NULL && L2!=NULL)
	{
		if(L1->data == L2->data){
			L4=insert_sort(L4,L1->data);
			L1=L1->next;
			L2=L2->next;
		}
		else if(L1->data>L2->data){
			L2=L2->next;
		}
		else{
			L1=L1->next;
		}
	}
	return L4;
}
void display(NODE L){
	while(L!=NULL){
		printf("%d\t",L->data);
		L=L->next;
	}
	printf("\n");
}
int main()
{
	NODE L1=NULL;
	NODE L2=NULL;
	int f;
	int item=0;
	while(1){
		printf("1.Insert_sort_in_L1\n2.Insert_sort_in_L2\n3.Stop Insertion\n");
		scanf("%d",&f);
		if(f==1)
		{
			printf("Enter in L1\n");
			scanf("%d",&item);
			L1=insert_sort(L1,item);
		}
		if(f==2){
			int item;
			printf("Enter in L2\n");
			scanf("%d",&item);
			L2=insert_sort(L2,item);
		}
	if(f==3){
		printf("Stopping insertion of elements in both L1 AND L2\n");
		break;
	}
}
remove_node(L1);
remove_node(L2);
NODE L3=NULL;
L3=unionL1L2(L1,L2);
printf("Displaying union of L1 and L2\n");
display(L3);
free(L3);
NODE L4=NULL;
L4=interL1L2(L1,L2);
printf("Displaying intersection of L1 and L2\n");
display(L4);
free(L4);
}



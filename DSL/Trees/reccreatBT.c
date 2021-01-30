#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}*NODE;

void printPreorder(NODE root)
{	printf("%d ",root->data);
	printPreorder(root->left);
	printPreorder(root->right);
}
NODE getNODE()
{
	NODE new=(NODE)malloc(sizeof(struct node));
	return new;
}
NODE createBT()
{
	NODE p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(NODE)malloc(sizeof(struct node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=createBT();
 
	printf("Enter right child of %d:\n",x);
	p->right=createBT();
	
	return p;

}

int main()
{
	NODE root=NULL;
	int item;
	printf("Creating a tree\n");
	//printf("Enter the root element\n");
	//scanf("%d",&item);
	root=createBT();
	printPreorder(root);
}
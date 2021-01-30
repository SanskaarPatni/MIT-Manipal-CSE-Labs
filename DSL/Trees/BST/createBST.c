#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}*NODE;
void printInorder(NODE root)
{
	if(root!=NULL){
	printInorder(root->left);
	printf("%d ",root->data);
	printInorder(root->right);
}
}
NODE createBST(NODE root,int data)
{
	NODE new=(NODE)malloc(sizeof(struct node));
	new->data=data;
	new->right=new->left=NULL;
	if(root==NULL)
	{
		return new;
	}
	NODE prev=NULL;
	NODE curr=root;
	while(curr!=NULL)
	{
		prev=curr;
		if(data<curr->data)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	if(prev->data<data)
	{
		prev->right=new;
	}
	else
	{
		prev->left=new;
	}
	return root;
}

int main()
{
		NODE root=NULL;
		while(1)
		{
			printf("1.Keep Inserting\n0.Stop Inserting\n");
			int t;
			scanf("%d",&t);
			if(t){
			printf("Enter data to be inserted\n");
				int num;
				scanf("%d",&num);
				root=createBST(root,num);
			}
			else{
				break;
			}
		}
		printInorder(root);

}
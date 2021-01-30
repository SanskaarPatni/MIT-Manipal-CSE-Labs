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
NODE deleteIt(NODE root,int ele)
{
	if(root==NULL)
	{
		printf("Empty Tree\n");
	}
	NODE succ,curr,parent,child;
	parent=NULL;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==ele)
		break;

		parent=curr;
		if(ele<curr->data)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	if(curr==NULL)
	{
		printf("Element not found\n");
		return root;
	}
	else if(curr->left==NULL && curr->right ==NULL)
	{
		if(parent->left==curr){
			parent->left=NULL;
		}
		else{
			parent->right=NULL;
		}
		
		free(curr);
		return root;
	}
	else if(curr->left==NULL)
	{
		child=curr->right;
	}
	else if(curr->right==NULL)
	{
		child=curr->left;
	}
	else
	{
		succ=curr->right;
		while(succ->left!=NULL)
		{
			succ=succ->left;
		}
		succ->left=curr->left;
		child=curr->right;
	}

	if(parent==NULL)
	{
		return child;
	}
	if(curr==parent->left)
	{
		parent->left=child;
	}
	else
	{
		parent->right=child;
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
		printf("\nWhich Element should be deleted\n");
		int t;
		scanf("%d",&t);
		root=deleteIt(root,t);
		printInorder(root);

}
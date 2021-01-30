#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *l;
	struct node*r;
}*NODE;
NODE createNODE(int data)
{
	NODE new=(NODE)malloc(sizeof(struct node));
	new->l=new->r=new;
	new->data=data;
	return new;
}
NODE insertFront(NODE first,int data)
{
	NODE new=createNODE(data);
	if(first->l==first)
	{
		first->r=new;
		new->l=first;
		new->r=first;
		first->l=new;
	}
	else
	{
		new->r=first->r;
		first->r->l=new;
		first->r=new;
		new->l=first;
	}
	return first;
}
NODE deletel(NODE root,int k)
{
	if(root->l==root)
	{
		printf("List is empty\n");
		return root;
	}
	else if(root->r->r==root)
	{
		NODE p=root->r;
		if(p->data>k)
		{
			root->r=root;
			root->l=root;
			free(p);
			return root;
		}
	}
	else{
		NODE a=root->r;
		while(a!=root)
		{
			if(a->data>k)
			{
				NODE dup=a;
				a->l->r=a->r;
				a->r->l=a->l;
				a=a->r;
				dup->l=dup->r=NULL;
				free(dup);
			}
			else{
				a=a->r;
			}

		}

	}
return root;
}
void display(NODE first)
{
	NODE a=first->r;
	if(a==first)
	{
		printf("List is empty");
	}
	else{
	while(a!=first)
	{
		printf("%d ",a->data);
		a=a->r;
	}
}
}
int main()
{
	printf("Enter number of elements to be inserted int he list");
	int n;
	scanf("%d",&n);
	NODE first=(NODE)malloc(sizeof(struct node));
	first->l=first->r=first;
	for(int i=0;i<n;i++)
	{
		int data;
		scanf("%d",&data);
		first=insertFront(first,data);

	}
	printf("\n");
	display(first);
	printf("\n");
	first=deletel(first,5);
	display(first);
}
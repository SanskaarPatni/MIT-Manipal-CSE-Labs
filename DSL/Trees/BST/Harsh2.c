#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *lchild,*rchild;
}*NODE;
NODE search(NODE root,int ele)
{
    if(ele>root->data&&root->rchild!=NULL)
    {
        search(root->rchild,ele);
    }
    else if(ele>root->data&&root->rchild==NULL)
    {
        return root;
    }
    else if(ele<root->data&&root->lchild!=NULL)
    {
        search(root->lchild,ele);
    }
    else if(ele<root->data&&root->lchild==NULL)
    {
        return root;
    }
}
void insert(NODE root,int ele)
{
    NODE t=(NODE)malloc(sizeof(struct node));
    t=search(root,ele);
    NODE n=(NODE)malloc(sizeof(struct node));
    n->data=ele;
    n->rchild=NULL;
    n->lchild=NULL;
    if(ele>t->data)
    {
        t->rchild=n;
    }
    else
    {
        t->lchild=n;
    }
}
int check(NODE root,int x)
{
    return(root->data==x);
}
void inorsuc(NODE root,int x,int *s)
{
    static int flag=0;
    if(root==NULL)
    return ;
    if(flag==1)
    {
        *s=root->data;flag=0;
    }
    else
    {
        inorsuc(root->lchild,x,s);
        if(check(root,x))
        flag=1;
        inorsuc(root->rchild,x,s);
    }
}
int main()
{
    int arr[20];
    int n;
    int i;
    printf("\nINPUT THE NUMBER OF ELEMENTS: ");
    scanf("%d",&n);
    printf("\nINPUT THE ELEMENTS: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    NODE root=(NODE)malloc(sizeof(struct node));
    root->data=arr[0];
    root->lchild=NULL;
    root->rchild=NULL;
    i=1;
    while(i<n)
    {
        insert(root,arr[i]);
        i=i+1;
    }
    int x;
    printf("INPUT THE NUMBER TO FIND THE INORDER SUCCESSOR: ");
    scanf("%d",&x);
    int m;
    inorsuc(root,x,&m);
    printf("INORDER SUCCESSOR IS: %d\n",m);
}
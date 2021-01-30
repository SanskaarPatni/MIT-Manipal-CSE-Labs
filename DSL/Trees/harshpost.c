#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
char data;
struct node *lchild,*rchild;
}*NODE;
void  streverse(char arr[])
{
    int i=0;
    int c=0;
    while(arr[i]!='\0')
    {
        c++;
        i++;
    }
    i=0;
    while(i<c/2)
    {
        char t=arr[i];
        arr[i]=arr[c-i-1];
        arr[c-i-1]=t;
        i++;
    }
}
int check(char ch) 
{ 
if(ch=='+'||ch=='-'||ch=='/'||ch=='*') 
return 2; 
else 
return 1; 
}
int cal(struct node* root) 
{ 
    int ch=check(root->data);
    if(ch==1)
    return (root->data-48);
    else if(ch==2) 
    { 
        if(root->data=='+') 
            return cal(root->lchild)+cal(root->rchild); 
        if(root->data=='-') 
            return cal(root->lchild)-cal(root->rchild); 
        if(root->data=='*') 
            return cal(root->lchild)*cal(root->rchild); 
        if(root->data=='/') 
            return cal(root->lchild)/cal(root->rchild); 
    } 
}
int main()
{
    char st[20];
    printf("INPUT THE POSTFIX EXPRESSION [assume single digit numbers only]: ");
    scanf("%[^\n]",st);
    streverse(st);
    int i=0;
    NODE root=(NODE)malloc(sizeof(struct node));
    root->data=st[i++];
    root->rchild=NULL;
    root->lchild=NULL;
    NODE temp=root;
    while(st[i]!='\0')
    {
        if(st[i]>='0'&&st[i]<='9')
        {
            NODE n=(NODE)malloc(sizeof(struct node));
            n->data=st[i];
            n->lchild=NULL;
            n->rchild=NULL;
            if(temp->rchild==NULL)
            temp->rchild=n;
            else
            {
                temp->lchild=n;i++;
                break;
            }    
        }
        else
        {
            NODE n=(NODE)malloc(sizeof(struct node));
            n->data=st[i];
            n->lchild=NULL;
            n->rchild=NULL;
            temp->lchild=n;
            temp=temp->lchild;
        }
        i=i+1;
    }
    while(st[i]!='\0')
    {
        NODE p=root;
        while(p->lchild!=temp)
        {
            p=p->lchild;
        }
        NODE n=(NODE)malloc(sizeof(struct node));
        n->data=st[i];
        n->lchild=NULL;
        n->rchild=NULL;
        p->rchild=n;
        temp=p;
        i++;
    }
    printf("EVALUATION: %d",cal(root));
}

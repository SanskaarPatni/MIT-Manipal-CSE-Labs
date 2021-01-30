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
NODE searchele(NODE root,int ele,NODE *prev)
{
    if(root->data==ele)
    {
        return root;
    }
    else if(root->data<ele)
    {
        *prev=root;
        searchele(root->rchild,ele,prev);
    }
    else if(root->data>ele)
    {
        *prev=root;
        searchele(root->lchild,ele,prev);
    }
}
NODE largest(NODE root)
{
    if(root->rchild==NULL)
    {
        return root;
    }
    else
    {
        largest(root->rchild);
    }
}
/*void delete(NODE root,int ele)
{
    NODE prev=(NODE)malloc(sizeof(struct node));
    NODE t=(NODE)malloc(sizeof(struct node));
    t=searchele(root,ele,&prev);
    NODE temp=(NODE)malloc(sizeof(struct node));
    if(t->lchild!=NULL)
    {
        temp=largest(t->lchild);
        temp->rchild=t->rchild;
        if(ele>prev->data)
        {
            prev->rchild=temp;
        }
        else
        {
            prev->lchild=temp;
        }
        free(t);
        return;
    }
    else if(t->lchild==NULL)
    {
        if(ele>prev->data)
        prev->rchild=t->rchild;
        else
        prev->lchild=t->rchild;
        free(t);
        return;
    }
    else if(t->lchild==NULL&&t->rchild==NULL)
    {
        if(ele>prev->data)
        {
            prev->rchild=NULL;
        }
        else
        {
            prev->lchild=NULL;
        }
        free(t);
        return;
    }

}*/
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->rchild = delete(root->rchild, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->rchild==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
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
void inorder(NODE root)
{
    if(root==NULL)
    return;
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
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
    int x;
    i=1;
    while(i<n)
    {
        insert(root,arr[i]);
        i=i+1;
    }
    printf("INORDER TRAVERSAL: ");
    inorder(root);
    printf("\n");
    int c;
    do
    {
        printf("\nINPUT YOUR CHOICE:\n");
        printf("1.DELETE ELEMENT\t2.DISPLAY INORDER\t3.EXIT\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("INPUT THE ELEMENT TO DELETE: ");
            scanf("%d",&x);
            delete(root,x);
            break;
            case 2:
            printf("INORDER TRAVERSAL: ");
            inorder(root);
            printf("\n");
            break;
            case 3:
            printf("\n*********EXITING STATUS******\n");
            break;
        }
    }while(c!=3);
}
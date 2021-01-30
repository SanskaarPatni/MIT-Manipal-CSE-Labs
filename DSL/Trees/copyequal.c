#include <stdio.h> 
#include <stdlib.h> 
#include "btree.h"
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
NODE copyy(NODE root)
{
    NODE temp;
    if(root==NULL)
    {
        return NULL;
    }
    temp=newNode(root->data);
    temp->left=copyy(root->left);
    temp->right=copyy(root->right);
    return temp;
}

int equal(NODE root1,NODE root2){
    return((!root1 && !root2)||(root1 && root2 && (root1->data==root2->data) && equal(root1->left,root2->left) && equal(root1->right,root2->right)));

}
int main() 
{ 

    char path[20];
    //struct node* root=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to be inserted to root:");
    int d;
    scanf("%d",&d);
    NODE root=newNode(d);
    int flag=1;
    while(flag==1){
    printf("Enter path:\n");
    scanf("%s",path);
    create_bt(root,path);
    printf("1.Continue insertion\n2.Stop\n");
    scanf("%d",&flag);
    }
    printf("Making a copy of binary tree..\n");
    NODE cpy=copyy(root);
    // printf("Infix of original tree:\n");
    // printInorder(root);
    // printf("\nInfix of duplicated tree:\n");
    // printInorder(cpy);
    printf("\nUsing the recursive equal function to check if the two trees are equal:\n");
    int f=equal(root,cpy);
    if(f==1)
    {
        printf("The trees are equal\n");
    }
    else{
        printf("Unequal trees\n");
    }
    return 0; 
} 
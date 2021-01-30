#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
  
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(node->left); 
  
     // then recur on right subtree 
     printPostorder(node->right); 
  
     // now deal with the node 
     printf("%d ", node->data); 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(node->left); 
  
     /* then print the data of node */
     printf("%d ", node->data);   
  
     /* now recur on right child */
     printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
    
     printf("%d ", node->data);   
  
     
     printPreorder(node->left);   
  
     
     printPreorder(node->right); 
}    
void create_bt(struct node* root,char *p){
    struct node *temp,*prev,*curr=root;
    int i=0;
    int f;
    printf("Enter data to be inserted into the new node:");
    scanf("%d",&f);
    temp=newNode(f);
    while(curr!=NULL){
        prev=curr;
        if(*(p+i)=='L' || *(p+i)=='l')
        {
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        i++;
        }
        if(curr!=NULL || *(p+i)!='\0'){
            printf("Insertion not possible\n");
            return ;
        }
        i=i-1;
        if(*(p+i)=='L' || *(p+i)=='l'){
            prev->left=temp;
        }
        else{
            prev->right=temp;
        }
}

  

int main() 
{ 

    char path[20];
    //struct node* root=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to be inserted to root:");
    int d;
    scanf("%d",&d);
    struct node* root=newNode(d);
    int flag=0;
    while(flag==0){
    printf("Enter path:\n");
    scanf("%s",path);
    create_bt(root,path);
    printf("0.Continue insertion\n1.Stop\n");
    scanf("%d",&flag);
    }
    printf("\nPreorder traversal of binary tree is \n"); 
    printPreorder(root); 
  
    printf("\nInorder traversal of binary tree is \n"); 
    printInorder(root);   
  
    printf("\nPostorder traversal of binary tree is \n"); 
    printPostorder(root); 
    return 0; 
} 
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
};  
struct node* newNode (int data) 
{ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
}  
struct node* constructTreeUtil (int pre[], int post[], int* preIndex, 
                                int l, int h, int size) 
{  
    if (*preIndex >= size || l > h) 
        return NULL;   
    struct node* root = newNode ( pre[*preIndex] ); 
    ++*preIndex;  
    if (l == h) 
        return root;  
    int i; 
    for (i = l; i <= h; ++i) 
        if (pre[*preIndex] == post[i]) 
            break;  
    if (i <= h) 
    { 
        root->left = constructTreeUtil (pre, post, preIndex,l, i, size); 
        root->right = constructTreeUtil (pre, post, preIndex,i + 1, h, size); 
    } 
  
    return root; 
}  
struct node *constructTree (int pre[], int post[], int size) 
{ 
    int preIndex = 0; 
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size); 
}  
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
}
int main () 
{ 
    int pre[20]; 
    int post[20]; 
    int size; 
    printf("INPUT THE SIZE OF THE ARRAY: ");
    scanf("%d",&size);
    printf("\nASSUME SINGLE DIGIT NUMBERS AND INPUT AS AN ARRAY\n");
    int i;
    printf("INPUT PREORDER: ");
    for(i=0;i<size;i++)
    scanf("%d",&pre[i]);
    
    printf("INPUT POSTORDER: ");
    for(i=0;i<size;i++)
    scanf("%d",&post[i]);
    struct node *root = constructTree(pre, post, size); 
    printf("\n");
    printf("Inorder traversal of the constructed tree: "); 
    printInorder(root); 
    printf("\n");
    return 0; 
} 
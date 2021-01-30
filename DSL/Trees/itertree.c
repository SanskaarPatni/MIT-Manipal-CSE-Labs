#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}*NODE; 
struct StackPost{
    NODE addr;
    int flag;
}s[50];
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
NODE newNode(int data) 
{ 
     NODE node = (NODE)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
  
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPreorder(NODE root) 
{ 
    //stack is an array of pointr damnnn
    NODE stack[50];
    int top=-1;
    if(root==NULL){
        printf("Tree is empty\n");
    }
    for(;;){
        while(root!=NULL){
            printf("%d ",root->data);
            stack[++top]=root;
            root=root->left;
        }
        if(top!=-1){
            root=stack[top--];
            root=root->right;
        }
        else{
            return;
        }
    }
} 

void printInorder(NODE root){
    NODE stack[50];
      int top=-1;
    if(root==NULL){
        printf("Tree is empty\n");
    }
    for(;;){
        while(root!=NULL){
            stack[++top]=root;
            root=root->left;
        }
        if(top!=-1){
            root=stack[top--];
            printf("%d ",root->data);
            root=root->right;
        }
        else{
            return;
        }
    }
}
void printPostorder(NODE root){
    if(root==NULL){
        printf("The tree is empty\n");
        return;
    }
    int top=-1;
    while(1){
        while(root!=NULL){
            top++;
            s[top].addr=root;
            s[top].flag=1;
            root=root->left;
        }
        while(s[top].flag==0){
            root=s[top].addr;
            top--;
            printf("%d ",root->data);
            if(top==-1){
                return;
            }
        }
        root=s[top].addr;
        root=root->right;
        s[top].flag=0;
    }
}
  

void create_bt(NODE root,char *p){
    NODE temp,prev,curr=root;
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

int search(NODE root,int ele)
{
	static int t=0;
	if(root!=NULL)
	{
		printf("%d",root->data);
		if(root->data==ele)
		{
			t=1;
			return t;
		}
		if(t==0)
		{
			search(root->left,ele);
			search(root->right,ele);

		}}
} 
int count_leafnodes( NODE root){
static int count = 0;
if(root!=NULL){
	printf("%d ",count);
if(root->left==NULL && root->right==NULL)
count++;

count_leafnodes(root->left);

count_leafnodes(root->right);
}

return count;
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
    printf("\nPreorder traversal of binary tree is \n"); 
    printPreorder(root); 
  
    printf("\nInorder traversal of binary tree is \n"); 
    printInorder(root);   
  
    printf("\nPostorder traversal of binary tree is \n"); 
    printPostorder(root); 
    printf("Number of leaf nodes\n");
    int count=count_leafnodes(root);
    printf("%d\n",count);
    printf("Enter the element to be searched\n");
    int data;
    scanf("%d",&data);
    int t=search(root,data);
    if(t)
    {
    	printf("Element found\n");
    }
    else{
    	printf("Element not found\n");
    }
    return 0; 
} 
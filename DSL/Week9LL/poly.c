#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coeff;
	int exp;
	struct node *next;
}*NODE;
NODE insertsort(NODE l,int c,int e){
	NODE n=(NODE)malloc(sizeof(struct node));
	n->coeff=c;
	n->exp=e;
	n->next=NULL;
	if(l==NULL){
		return n;
	}
	if(e<=l->exp){
		n->next=l;
		return n;
	}
NODE prev,curr=l;
while(curr!=NULL && e>curr->exp){
	prev=curr;
	curr=curr->next;
}
prev->next=n;
n->next=curr;
return l;
}
void display(NODE f)
{
    NODE t=f;
    printf("\nLIST ELEMENTS: ");
    while(t->next!=NULL)
    {
        if((t->next)->coeff>=0)
        printf("%dX^%d+",t->coeff,t->exp);
        else
        printf("%dX^%d",t->coeff,t->exp);
        t=t->next;
    }
    printf("%dX^%d\n",t->coeff,t->exp);
}
void subtract(NODE l1,NODE l2){
	int c;
	int diff;
	NODE l3=NULL;
	while(l1!=NULL && l2!=NULL){
		if(l1->exp==l2->exp)c=0;
		else if(l1->exp<l2->exp)c=1;
		else c=2;
		switch(c){
			case 0:
			diff=l1->exp-l2->exp;
			if(diff){
				l3=insertsort(l3,diff,l1->exp);
			}
			l1=l1->next;
			l2=l2->next;
			break;
			case 1:
			l3=insertsort(l3,l1->coeff,l1->exp);
			l1=l1->next;
			break;
			case 2:
			l3=insertsort(l3,l1->coeff,l1->exp);
			l1=l1->next;
			break;
		}
}
	while(l1!=NULL){
		l3=insertsort(l3,l1->coeff,l1->exp);
		l1=l1->next;
	}
	while(l2!=NULL){
		l3=insertsort(l3,l2->coeff,l2->exp);
		l2=l2->next;
	}
	display(l3);
}
NODE multiply(NODE poly1,NODE poly2,NODE poly3){
NODE ptr1, ptr2; 
    ptr1 = poly1; 
    ptr2 = poly2; 
    while (ptr1 != NULL) { 
        while (ptr2 != NULL) { 
            int coeff, power; 
  
            // Multiply the coefficient of both 
            // polynomials and store it in coeff 
            coeff = ptr1->coeff * ptr2->coeff; 
  
            // Add the powerer of both polynomials 
            // and store it in power 
            power = ptr1->exp + ptr2->exp; 
  
            // Invoke addnode function to create 
            // a newnode by passing three parameters 
            poly3 = insertsort(poly3, coeff, power); 
  
            // move the pointer of 2nd polynomial 
            // two get its next term 
            ptr2 = ptr2->next; 
        } 
  
        // Move the 2nd pointer to the 
        // starting point of 2nd polynomial 
        ptr2 = poly2; 
  
        // move the pointer of 1st polynomial 
        ptr1 = ptr1->next; 
    } 
  
    // this function will be invoke to add 
    // the coefficient of the elements 
    // having same powerer from the resultant linked list 
    removedup(poly3);
    return poly3; 
} 
void removedup(NODE poly3){
	NODE curr=poly3;
	while(curr!=NULL && curr ->next!=NULL)
	{	
		if(curr->exp==curr->next->exp){
			NODE dup=curr->next;
			curr->coeff=curr->coeff+dup->coeff;
			curr->next=dup->next;
			free(dup);
		}
		else{
			curr=curr->next;
		}
	}
}

int main()
{
    NODE f=NULL;
    NODE s=NULL;
    int ch;
    int c;
    int e;
    printf("INPUT THE FIRST LIST:");
    do
    {
        printf("\nINPUT YOUR CHOICE\n");
        printf("1.PUSH\t2.EXIT AND INPUT NEW LIST\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("INPUT COEFFICIENT AND EXPONENT:\n");
            scanf("%d%d",&c,&e);
            f=insertsort(f,c,e);
            break;
            case 2:
            printf("\nINPUT SECOND LIST:");
            break;
        }
    }while(ch!=2);
    do
    {
        printf("\nINPUT YOUR CHOICE\n");
        printf("1.PUSH\t2.EXIT AND INPUT NEW LIST\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("INPUT COEFFICIENT AND EXPONENT:\n");
            scanf("%d%d",&c,&e);
            s=insertsort(s,c,e);
       
            break;
            case 2:
            printf("\nDISPLAYING GIVEN LISTS:\n");
            break;
        }
    }while(ch!=2);
    display(f);
    display(s);
 
    printf("\nAFTER SUBTRACTION:");
    subtract(f,s);
    printf("\nAFTER MULTIPLICATION:");
    NODE l3=NULL;
    l3=multiply(f,s,l3);
    display(l3);
    return 0;
}

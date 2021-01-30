#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *llink,*rlink;
}*NODE;

void Display(NODE first){
	NODE temp=first->rlink;
	while(temp!=first){
		printf("%d",temp->data);
		temp=temp->rlink;
	}
	printf("\n");
}
void insertDIFF_frontCDL(int ele,NODE first)
{
	NODE n=(NODE)malloc(sizeof(struct node));
	n->data=ele;
	n->rlink=n->llink=n;

	first->rlink->llink=n;
	n->rlink=first->rlink;
	n->llink=first;
	
	first->rlink=n;
}
NODE readLongInt(){
	NODE head=(NODE)malloc(sizeof(struct node));
	head->rlink=head->llink=head;
	char str[100];
	int i,n;
	printf("Enter the string representing long integer:\n");
	scanf("%s",str);
	for(n=0;str[n]!='\0';n++);
	for(i=n-1;i>=0;i--){
		insertDIFF_frontCDL(str[i]-'0',head);
	}
	return head;
}
NODE AddLongInt(NODE A,NODE B){
	int digit,sum,carry;
	NODE head,r,R,a,b;
	int flag=1;
	head=(NODE)malloc(sizeof(struct node));
	head->rlink=head->llink=head;
	carry=0;
	a=A->llink;
	b=B->llink;
	printf("a%d ",a->data);
	printf("b%d ",b->data);
	while(a!=A && b!=B){
		sum=0;
		sum=a->data+b->data+carry;
		carry=0;
		digit=sum%10;
		carry=sum/10;
		insertDIFF_frontCDL(digit,head);
		a=a->llink;
		b=b->llink;

	}
	if(a!=A){
		r=a;R=A;
		flag=0;
	}
	if(b!=B){
		r=b;R=B;
		flag=0;
	}
	if(flag==0){
	while(r!=R)
	{
		sum=0;
		sum=r->data+carry;
		carry=0;
		digit=sum%10;
		carry=sum/10;
		insertDIFF_frontCDL(digit,head);
		r=r->llink;

}	}

	if(carry){
		insertDIFF_frontCDL(carry,head);
	}

	return head;
}
int main(){
	NODE a,b,sum;
	a=readLongInt();
	b=readLongInt();
	printf("\nFirst Integer\n");
	Display(a);
	printf("Second Integer\n");
	Display(b);
	sum=AddLongInt(a,b);
	printf("Sum is:\n");
	Display(sum);
	return 0;
}
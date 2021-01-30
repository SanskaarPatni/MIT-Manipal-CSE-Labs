#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct
{
	char q[MAX][20];
	int f,r;
}queue;
void insertcq(queue *q1,char ele[])
{
	if(q1->r==MAX-1 && q1->f==0)
		printf("Queue is full\n");
	else if(q1->r==-1 && q1->f==-1)
	{
		q1->f=q1->r=0;
		strcpy(q1->q[q1->r],ele);
	}
	else if(q1->f!=0&& q1->r==MAX-1)
	{
		q1->r=0;
		strcpy(q1->q[q1->r],ele);
	}
	else
	{
		q1->r++;
        strcpy(q1->q[q1->r],ele);
	}
}
char * deletecq(queue *q1)
{
	if(q1->r==-1 && q1->f==-1)
		printf("Queue is empty\n");
	char* val=(char*)calloc(20,sizeof(char)); 
	strcpy(val,q1->q[q1->f]);
	if(q1->f==q1->r)
		{
			q1->f=q1->r=-1;
			return val;
		}
	else if(q1->f==MAX-1)
		{
			q1->f=0;
			return val;
		}
	else
		{
			q1->q[q1->f++];
			return val;
		}
}
void displaycq(queue *q1)
{
	int i;
	if(q1->r==-1 && q1->f==-1)
		printf("Queue is empty\n");
	else
	{
		if((q1->f)>(q1->r))
	{
			for(i=q1->f;i<MAX;i++)
				printf("\t %s\n", q1->q[i]);
			for(i=0;i<=q1->r;i++)
				printf("\t %s\n", q1->q[i]);
		}
		else{
		for(i=q1->f;i<=q1->r;i++)
			printf("\t %s\n", q1->q[i]);
		}
	
	}

}
int main()
{
	queue q1;
	q1.f=-1;
	q1.r=-1;
	int ch;
	char val[20],ele[20];
	do
	{
		printf("1. Insert\t\t2. Delete\t\t3. Display\t\t4. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted:");
				scanf("%s",ele);
				insertcq(&q1,ele);
				printf("Inserted\n");
				break;
			case 2:
				
				strcpy(val,deletecq(&q1));
				printf("The character deleted is:%s\n",val);
				break;
			case 3:
				printf("Queue elememts are:\n");
				displaycq(&q1);
				break;
			case 4: exit(0);
		}
	}while(ch!=4);
}
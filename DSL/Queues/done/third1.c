#include<stdio.h>
#define MAX 20
typedef struct {
int x[MAX];
int front;
int rear;
} queue;
void insertq(queue *, int);
void displayq(queue);
int deleteq(queue *);
void insertq(queue * q,int x)
{
if(q->rear==MAX)
{
printf("\nOverflow\n");
}
else
{
q->x[++q->rear]=x;
if(q->front==-1)
{
q->front=0;
}
}
}
int deleteq(queue * q)
{
int x;
if(q->front==-1)
{
printf("\nUnderflow!!!\n");
}
else if(q->front==q->rear)
{
x=q->x[q->front];
q->front=q->rear=-1;
return x;
}
else
{
return q->x[q->front++];
}
}
void displayq(queue q)
{
int i;
if(q.front==-1&&q.rear==-1)
{
printf("\nQueue is Empty!!!");
}
else
{
printf("\nQueue is:\n");
for(i=q.front;i<=q.rear;i++)
{
printf("%d\n",q.x[i]);
}
}
}
int searchcq(queue *cq, int ele){
	int flag=0;
	if(cq->front==-1){
		printf("Empty!\n");
	}
	else{
		for(int i=0;i<6;i++)
		{
			
			int outEle = deleteq(cq);
			if(outEle==ele){
				flag=1;
			}			
			insertq(cq, outEle);
			
		}
	}
	return flag;
}
int main(){
	queue cq;
	cq.front=-1;
	cq.rear=-1;
	int ele;
	printf("Insert elements in the queue: ");
	for(int i=0;i<6;i++){
		scanf("%d", &ele);
		insertq(&cq, ele);
	}
	printf("The queue is: \n");
	displayq(cq);
	printf("\nInsert element to be searched: ");
	scanf("%d", &ele);
	if(searchcq(&cq, ele)){
		printf("Found");
	}else{
		printf("Not found");	
	}
	printf("\nNow the queue is:\n");
	displayq(cq);
	return 0;
}
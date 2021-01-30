#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#define PAX 10
typedef struct
{
	int x[PAX];
	int front;
	int rear;
}queue;
void enqueueRear(queue *q,int p)
{
	if (q->rear == MAX -1)
		printf("Full from right\n");
	else
	{
		q->x[++q->rear]=p;
		if (q->front == -1)
			q->front = 0;
	}
}
int dequeueFront(queue *q)
{
	if (q->rear == -1 && q->front == -1)
	{
		printf("Empty dequeue\n");
		return '#';
	}
	else if (q->front == q->rear)
	{
		int val=q->x[q->front];
		q->front = q->rear = -1;
		return val;
	}
	else
		return q->x[q->front++];
}

void display(queue *q)
{
	int i;
	if (q->front == -1 && q->rear == -1)
		printf("Empty dequeue\n");
	else
	{
		printf("Dequeue is\n");
		for (i=q->front; i<=q->rear; i++)
			printf("%d\n", q->x[i]);
	}
}

int main()
{
	queue q;
	stack s;
	s.top=-1;
	q.front = -1;
	q.rear = -1;
	int n;
	printf("Enter number of integers\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter integer:\n");
		int num;
		scanf("%d",&num);
		enqueueRear(&q,num);
	}
	printf("Queue initially:\n");
	display(&q);
	for(int i=0;i<n;i++){

		push(&s,dequeueFront(&q));
	}
	for(int i=0;i<n;i++){
		enqueueRear(&q,pop(&s));
	}
	printf("Queue finally:\n");
	display(&q);
	return 0;
}
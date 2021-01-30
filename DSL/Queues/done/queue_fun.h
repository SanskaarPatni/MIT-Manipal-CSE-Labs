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
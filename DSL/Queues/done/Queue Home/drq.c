#include <stdio.h>

# define MAX 100

typedef struct
{
	int x[MAX];
	int front;
	int rear;
} Q;

Q q;

void enqueueRight(int);
void display();
int dequeueLeft();
void enqueueLeft(int);

int main()
{
	q.front = -1;
	q.rear = -1;
	int ch, x, flag = 1;
	while (flag)
        {
                printf("1. Enqueue Left\n2. Enqueue Right\n3. Dequeue\n4. Display\n");
                scanf("%d", &ch);
                switch (ch)
                {
                         case 1:
                               printf("Enter element\n");
                               scanf("%d", &x);
                               enqueueLeft(x);
                               break;
                         case 2:
                               printf("Enter element\n");
			       scanf("%d", &x);
			       enqueueRight(x);
                               break;
                         case 3:
                               x = dequeueLeft();
                               printf("Deleted element is %d\n", x);
                               break;
                         case 4:
                               display();
                               break;
                         default : 
                               flag = 0;
                               break;
                 }
	 }
	return 0;
}

void enqueueRight(int x)
{
	if (q.rear == MAX)
		printf("Full from right\n");
	else
	{
		q.x[++q.rear] = x;
		if (q.front == -1)
			q.front = 0;
	}
}

void enqueueLeft(int x)
{
	if (q.rear == -1 && q.front == -1)
		enqueueRight(x);
	else if (q.front == 0)
		printf("Full from left\n");
	else
		q.x[--q.front] = x;
}

int dequeueLeft ()
{
	int x;
	if (q.rear == -1 && q.front == -1)
	{
		printf("Empty dequeue\n");
		return -32767;
	}
	else if (q.front == q.rear)
	{
		x = q.x[q.front];
		q.front = q.rear = -1;
		return x;
	}
	else
		return q.x[q.front++];
}

void display()
{
	int i;
	if (q.front == -1 && q.rear == -1)
		printf("Empty dequeue\n");
	else
	{
		printf("Dequeue is\n");
		for (i=q.front; i<=q.rear; i++)
			printf("%d\n", q.x[i]);
	}
}
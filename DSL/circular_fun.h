#define MAX 5
typedef struct{
	int x[MAX];
	int front;
	int rear;
}cqueue;

void insertcq(cqueue *, int);
int deletecq(cqueue *);
void displaycq(cqueue);
int searchcq(cqueue *, int);



void insertcq(cqueue *cq, int ele){
	if((cq->rear+1)%MAX==cq->front){
		printf("Overflow!\n");
	}
	else{
		if((cq->front)==-1)
			cq->front=0;
		cq->rear=(cq->rear+1)%MAX;
		cq->x[cq->rear]=ele;
	}
}

int deletecq(cqueue *cq){
	
	if(cq->front==-1)
		printf("Empty\n");
	else{
		int temp = cq->x[cq->front];
		if(cq->front==cq->rear)
			cq->front=cq->rear=-1;
		else
			cq->front=(cq->front+1)%MAX;
		return temp;		
	}
}

void displaycq(cqueue cq){
	if(cq.front==-1)
		printf("Empty!\n");
	
	else if((cq.rear)>=(cq.front)){
		for(int i=cq.front; i<=cq.rear; i++){
			printf("%d\t", cq.x[i]);
		}
		printf("\n");
	}
	else{
		for(int i=cq.front; i<MAX; i++){
			printf("%d\t", cq.x[i]);
		}
		for(int i=0;i<=cq.rear; i++){
			printf("%d\t", cq.x[i]);
		}
		printf("\n");
	}
}

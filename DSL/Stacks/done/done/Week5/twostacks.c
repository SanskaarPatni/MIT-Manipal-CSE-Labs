#include<stdio.h>
#define MAX 20
typedef struct{
	int a[MAX];
	int top1=-1;
	int top2=MAX;
}stack;
void pushs1(stack *s,int data){
	if(s->top1 < (s->top2-1)){
		s.a[++(s.top1)]=data;
	}
	else{
		printf("Stack full");
	}
}
void pushs2(stack *s,int data){
	if(s->top1 < (s->top2-1)){
		s.a[--(s.top2)]=data;
	}
	else{
		printf("Stack full");
	}
}
void popstack(stack *s){
	if((s->top1)>=0){
		int pvalue=s.a[s.top1--];
	    printf("%d is popped from Stack1 \n",pvalue);
	}
	else{
		printf("Stack is empty !Cannot pop\n");
	}
}
void popstack(stack *s){
	if((s->top2)<MAX){
		int pvalue=s.a[s.top2++];
	    printf("%d is popped from Stack1 \n",pvalue);
	}
	else{
		printf("Stack is empty !Cannot pop\n");
	}
}
void prints1(stack *s){
	int i=0;
	for(int i=s->top1;i>=0;--i){
		printf("%d\t",s->a[i]);
	}
}
void prints1(stack *s){
	int i=0;
	for(int i=s->top2;i<MAX;++i){
		printf("%d\t",s->a[i]);

	}
}

int main(){
	stack s;
	
}


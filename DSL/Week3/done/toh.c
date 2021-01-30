#include<stdio.h>
long moves=0;
void tower(int n,char from,char inter,char to){
	moves++;
	if(n==1){
		printf("Move disk 1 from %c to %c\n",from,to);
		return ;

	}
	else
	{
		tower(n-1,from,to,inter);
		printf("Move disk %d from %c to %c\n",n,from,to);
		tower(n-1,inter,from,to);
	}


}
int main(){
	printf("Enter number of disks:\n");
	int n;scanf("%d",&n);
	tower(n,'a','b','c');
	printf("Total number of moves taken is %li\n",moves);
	return 0;
}
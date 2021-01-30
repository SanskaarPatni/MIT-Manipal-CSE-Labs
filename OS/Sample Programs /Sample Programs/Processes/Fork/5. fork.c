#include<stdio.h>
int main()
{
	int x=10;
	int p;
	if(fork()==0)
	{
		x++;
		printf("%d\n", x);
	}
	else
	{

//		wait(&p);
	printf("%d\n", x);
	}
}

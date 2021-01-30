#include<stdio.h>
int main()
{
if(	fork()==0)
{
	printf("Hello %d %d\n", getpid(), getppid());
}
else
{
	printf("Hi %d %d\n", getpid(), getppid());
}
}

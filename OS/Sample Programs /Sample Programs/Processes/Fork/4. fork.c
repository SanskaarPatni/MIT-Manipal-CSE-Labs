#include<stdio.h>
int main()
{
	int v;
	v=fork();
	printf("%d %d\n", v, getpid());
}

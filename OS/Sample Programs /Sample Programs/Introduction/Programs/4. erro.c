#include<stdio.h>
#include<errno.h>

int main()
{
	int i;
	extern int errno, sys_nerr;
	for(i=0;i<sys_nerr;++i)
	{
		fprintf(stderr,"%3d",i);	
		errno=i;
		perror(" ");
	}
}	

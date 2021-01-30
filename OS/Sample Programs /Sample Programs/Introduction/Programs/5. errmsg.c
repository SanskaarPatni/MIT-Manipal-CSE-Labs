#include<stdio.h>
#include<errno.h>

int main()
{
	int i;
	extern int sys_nerr;
	for(i=0;i<sys_nerr;++i)
		fprintf(stderr,"%3d : %s\n",i,sys_errlist[i]);
	return 0;
}

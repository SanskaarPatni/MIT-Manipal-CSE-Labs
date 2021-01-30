#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int i,n;
	pid_t childpid;

	if(argc!=2)
	{
		fprintf(stderr,"Usage : %s processes. \n", argv[0]);
		exit(1);
	}
//	n=atoi(argv[1]);
	
	childpid=0;
	for(i=1;i<n;i++)
		if(childpid=fork())
			break;
		if(childpid==-1)
		{
			perror("fork() failed : ");
			exit(1);
		}
	fprintf(stderr,"i : %d\nProcessID : %ld\nParentID : %ld\nChildID : %ld\n",i,(long)getpid(),(long)getppid(),(long)childpid);
	exit(0);
}

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main()
{
	char *a[3];
	int i;

	a[0]="xyz=/tmp";
	a[1]="pqr=/bin";
	a[2]="0";
	
	if(fork()==0)
	{
		for(i=0;environ[i];i++)
			printf("%s\n",environ[i]);
		execle("./a.out","a.out",0,a);
	}
	wait(&i);
	return 0;
}
#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main()
{
	char a[3],y[2];
	int i;

	a[0]="xyz=/tmp";
	a[1]="pqr=/bin";
	a[2]="0";
	
	y[0]="a.out";
	y[1]=0;
	
	if(fork()==0)
	{
		for(i=0;environ[i];i++)
			printf("%s\n",environ[i]);
		execve("./a.out",y,a);
	}
	wait(&i);
	return 0;
}

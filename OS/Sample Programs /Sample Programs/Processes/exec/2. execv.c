#include<stdio.h>
#include<unistd.h>

int main()
{
	char *a[4];
	a[0]="ls";
	a[1]="-a";
	a[2]="-l";
	a[3]=0;
	
	execv("/bin/ls",a);
}
#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Before execl function\n");
	
	execlp("ls","ls",0);
}
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/time.h>

int main()
{
	long now,time();
	char *ctime();
	
	time(&now);	
	
	printf("It is now %s",ctime(&now));	
}

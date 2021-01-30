#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/time.h>

int main()
{
	long now,time();
    struct tm *today, *localtime();
    
	time(&now);	
	today = localtime(&now);
	
	printf("Today is : %d/%d/%d.\n",today->tm_mon+1,today->tm_mday, today->tm_year);
}

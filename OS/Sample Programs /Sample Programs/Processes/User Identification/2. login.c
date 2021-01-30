#include<stdio.h>
#include<unistd.h>
#include<pwd.h>

int main()
{
	struct passwd *pass;
	char *name="visionx";
	
	if((pass=getpwnam(name)) != NULL)
	{
		printf("Home dir of %s is %s.\n",name,pass->pw_passwd);
	}	
	else
	{
		fprintf(stderr,"Can't find password info for %s.\n", name);
		exit(1);
	}
	exit(0);
}

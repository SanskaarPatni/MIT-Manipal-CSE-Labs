#include<stdio.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	char *login;
	if((login=getlogin()) != NULL)	
	{
		printf("Login Name : %s\n",login);
	}
	else
	{
		fprintf(stderr,"Can't find login name.\n");
		exit(1);
	}
	exit(0);
}

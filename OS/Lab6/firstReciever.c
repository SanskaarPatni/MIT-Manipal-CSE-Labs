#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	int some_integer;
};

int main()
{
	int a=0;
	int running=1;
	struct my_msg_st some_data;
	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr,"msgget failed!!\n");
		exit(EXIT_FAILURE);
	}
	while(running){
	if(msgrcv(msgid, &some_data, sizeof(int),0,0)==-1)
		{
		printf("msgsnd failed!!!\n");
		exit(EXIT_FAILURE);
		}
	else
	{
		a=some_data.some_integer;
		printf("Recieved Number: %d\n",a);
		int p = a;
		int r=0,s=0;
		while(p!=0)
		{
			r=p%10;
			s=s*10+r;
			p=p/10;
		}
		if(s==a)
			printf("Palindrome Number!!\n");
		else
			printf("NOT Palindrome Number\n");
		if(a==-999){
			running=0;
		}
	}
}
	if(msgctl(msgid,IPC_RMID,0)==-1){
		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
	}
	
	exit(EXIT_SUCCESS);
}
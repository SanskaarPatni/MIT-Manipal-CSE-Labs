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
		printf("Enter a number(-999 to exit): ");
		some_data.my_msg_type=1;
		scanf("%d",&a);
		some_data.some_integer=a;
		if(msgsnd(msgid, &some_data, sizeof(int),0)==-1)
		{
			printf("msgsnd failed!!!\n");
			exit(EXIT_FAILURE);
		}
		if(a==-999){
			running=0;
		}
	}
	exit(EXIT_SUCCESS);
}
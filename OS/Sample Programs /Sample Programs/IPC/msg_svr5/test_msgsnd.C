	#include <stdio.h>
	#include <string.h>
	#include <sys/ipc.h>
	#include <sys/msg.h>

	#ifndef MSGMAX
	#define MSGMAX     1024
	#endif


	struct mbuf 
	{
		long	mtype;
		char	mtext[MSGMAX];
	} mobj = { 15, "Hello" };


	int main()
	{

		int fd = msgget (100, IPC_CREAT|IPC_EXCL|0642);

		if (fd==-1 || msgsnd(fd,&mobj,strlen(mobj.mtext)+1, IPC_NOWAIT))

		perror("message");

		return 0;
	}

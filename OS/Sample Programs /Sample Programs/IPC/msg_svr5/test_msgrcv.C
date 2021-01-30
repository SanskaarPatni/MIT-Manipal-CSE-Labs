	#include <iostream.h>
	#include <stdio.h>
	#include <string.h>
	#include <sys/stat.h>
	#include <sys/ipc.h>
	#include <sys/msg.h>

	#ifndef MSGMAX
	#define MSGMAX     1024
	#endif


	/* data structure of one message */

	struct mbuf 
	{
		long	mtype;
		char	mtext[MSGMAX];
	} mobj = { 15, "Hello" };


	int main() 
	{

			int perm = S_IRUSR|S_IWUSR|S_IRGRP|S_IWOTH;
			int fd = msgget (100, IPC_CREAT|IPC_EXCL|perm);


			if (fd==-1 || msgsnd(fd,&mobj,strlen(mobj.mtext)+1,IPC_NOWAIT))
				perror("message");
			else if (msgrcv(fd,&mobj, MSGMAX,0,IPC_NOWAIT|MSG_NOERROR)>0)
				cout << mobj.mtext << endl;

			else perror("msgrcv");
			return 0;
	}

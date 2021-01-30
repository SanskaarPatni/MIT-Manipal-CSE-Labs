	#include <iostream.h>

	#include <stdio.h>
	#include <unistd.h>

	#include <sys/ipc.h>

	#include <sys/msg.h>

	int main() 

	{

			struct msqid_ds mbuf;

			int fd = msgget (100, 0);

			if (fd>0 && msgctl(fd,IPC_STAT,&mbuf)) 										{

				cout << "#msg in queue: " << mbuf.msg_qnum << endl;

				mbuf.msg_perm.uid = getuid(); 				// change owner user-ID

				if (msgctl(fd,IPC_SET,&mbuf)==-1) 

						perror("msgctl");

			} else

				perror("msgctl");

			if (msgctl(fd,IPC_RMID,0)) perror("msgctl - IPC_RMID");

			return 0;

	}

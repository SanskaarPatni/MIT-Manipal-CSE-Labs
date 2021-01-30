	#include <strstream.h>
	#include "message.h"
	#include <string.h>
	#include <signal.h>

	int main() 

	{

 		int      len, pid, cmdId;

   		char     buf[256];

 		time_t   tim;

   

   		/* setup this process as a daemon */

   		for (int i=0; i < 20; i++) signal(i,SIG_IGN);

   		setsid();

		cout << "server: start executing...\n" << flush;

   		message mqueue(MSGKEY);	// open a message queue

   		if (!mqueue.good()) exit(1);	// quit if queue open fails



   		/* wait for each request from a client */

      		while (len=mqueue.rcv(buf,sizeof(buf),-99,&cmdId) > 0) 

      		{

		/* extract a client's PID and check the PID is valid */

         		istrstream(buf,sizeof(buf)) >> pid;

         		if (pid < 100) 

		{

            		cerr << "Illegal PID: " << buf << '/' << pid << endl; 

			continue;

         		}



         			/* Prepare response to a client */

         		cerr<<"server: receive cmd #" <<cmdId

				<<", from client: "<<pid<<endl;

        		switch (cmdId) 

		{

            			case LOCAL_TIME: 

                 				tim = time(0);

                 					strcpy(buf,ctime(&tim));

                 				break;

            			case UTC_TIME: 

                 				tim = time(0);

                 				strcpy(buf,asctime(gmtime(&tim)));

                 				break;

            			case QUIT_CMD:

                 				cerr << "server: deleting msg queue...\n";

                 				return mqueue.rmQ();

            			default:	/* send an error msg back */

                 				ostrstream(buf,sizeof(buf)) << "Illegal cmd: " << cmdId << '\0';

          		}

		/* send response to a client */

          		if (mqueue.send(buf,strlen(buf)+1,pid)==-1)

              			cerr << "Server: " << getpid() << " send response fails\n";

		};  /* loop forever */

		return 0;

	}

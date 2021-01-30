	#ifndef MESSAGE_H

	#define MESSAGE_H




	#include <stdio.h>

	#include <stdlib.h>

	#include <memory.h>

	#include <unistd.h>

	#include <sys/ipc.h>

	#include <sys/msg.h>

	#include <sys/wait.h>



	/* common declarations for daemon/server process */

	enum { MSGKEY= 176, MAX_LEN =256, ILLEGAL_CMD = 4 };

	enum { LOCAL_TIME = 1, UTC_TIME = 2, QUIT_CMD = 3};



	typedef struct mgbuf 

	{

 	long 	mtype;

 	char 	mtext[MAX_LEN];

	} MSGBUF;



	class message 

	{

    		private:

     		int    msgId;	// message queue descriptor

    	 	struct mgbuf mObj;

	public:

		/* constructor. Get hold of a message queue */

       		message ( int key ) 

		{

           		if (msgId=msgget(key,IPC_CREAT|0666)==-1)

               			perror("msgget");

       		};



		/* destructor function. Do nothing */

      		 ~message () {};



		/* Check message queue open status */

       		int good () { return (msgId >= 0) ? 1 : 0; };





		/* remove a message queue */

       		int rmQ () 

		{ 

           			int rc=msgctl(msgId,IPC_RMID,0);

            			if (rc==-1) perror("msgctl");

            			return rc;

       		};



       		/* send a message */

       		int send ( const void* buf, int size, int type) 

       		{

			mObj.mtype = type;

            			memcpy(mObj.mtext,buf,size);

            			if (msgsnd(msgId,&mObj,size,0)) 															{ 

                				perror("msgsnd"); return -1;

            			};

            			return 0;

       		};     



       		/* receive a message */

       		int rcv ( void* buf, int size, int type, int* rtype) 

       		{

		int len = msgrcv(msgId,&mObj,MAX_LEN,type,MSG_NOERROR); 

            		if (len==-1) 								{ 

                			perror("msgrcv"); return -1;

            		}

            		memcpy(buf,mObj.mtext,len);

            		if (rtype) *rtype = mObj.mtype;

		return len;

       		};     

	};

	#endif

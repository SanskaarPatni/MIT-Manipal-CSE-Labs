	#ifndef MESSAGE3_H

	#define MESSAGE3_H

	#include <strstream.h>

	#include <stdio.h>

	#include <stdlib.h>

	#include <memory.h>

	#include <unistd.h>

	#include <sys/types.h>

	#include <sys/ipc.h>

	#include <sys/shm.h>

	#include <sys/sem.h>

	#include <sys/wait.h>

	#include <sys/errno.h>



	/* common declarations for daemon/server process */

	enum { MSGKEY=186, MAX_LEN=256, SHMSIZE=1024, SEMSIZE=2 };

	enum { LOCAL_TIME = 1, UTC_TIME = 2, QUIT_CMD = 3, 

			ILLEGAL_CMD = 4, SEM_RD = 0, SEM_WR=1 };



	struct mgbuf 

	{

    		long   	mtype;

    		char   	mtext[MAX_LEN];

	};



	class message 

	{

    		private:

      			int    shmId, semId;

      			struct mgbuf  *msgPtr;

      			enum ipc_op { 		RESET_SEM, CLIENT_GET_MEM, 

						CLIENT_SND_REQ, SERVER_RCV_REQ, 

             					SERVER_GET_MEM, SERVER_SND_RPY, 

					CLIENT_RCV_RPY

						};

    		public:

       			/* try to change semaphores' values */

       				void getsem( enum ipc_op  opType ) 

			{

           			static struct sembuf  args[2] = { {SEM_RD}, {SEM_WR} };

           			switch (opType) 				{

              				case SERVER_GET_MEM:  

						return;

              				case CLIENT_GET_MEM:  

					args[SEM_RD].sem_op = 0,

                                    				args[SEM_WR].sem_op = -1;

                                    			break;

              				case CLIENT_SND_REQ:  

					args[SEM_RD].sem_op = 1,

                                    			args[SEM_WR].sem_op = 0;

                                    			break;

              				case SERVER_RCV_REQ: 

					args[SEM_RD].sem_op = -1,

                                    			args[SEM_WR].sem_op = 0;

                                    			break;

              				case SERVER_SND_RPY: 

			a		rgs[SEM_RD].sem_op = 1,

                                    			args[SEM_WR].sem_op = 1;

                                   		 		break;

              				case CLIENT_RCV_RPY: 

					args[SEM_RD].sem_op = -1,

                                    			args[SEM_WR].sem_op = -1;

                                    			break;

              				case RESET_SEM:       

						args[SEM_RD].sem_op = 0,

                                    			args[SEM_WR].sem_op = 1;

			}

          				if (semop(semId,args,SEMSIZE)==-1) perror("semop");

       			};   



       			/* constructor function */

       			message( int key ) 

			{

           			if ((shmId=shmget(key, SHMSIZE, 0))==-1) 						{

              			if (errno==ENOENT) {				// create a brand new message object 

			if ((shmId= shmget(key, SHMSIZE, IPC_CREAT|0666)) ==-1)

                    				perror("shmget");

                 			else if ((semId=semget(key, SEMSIZE, IPC_CREAT|0666))

						==-1)

                    				perror("semget");

                 			else getsem(RESET_SEM);  // initialize a new semaphore set

              			} 

			else perror("shmget");

			} 

			else if ((semId=semget(key,0,0))==-1)  /* get existing semaphores */

              			perror("semget");



			if (shmId>=0 && !(msgPtr=(struct mgbuf*)shmat(shmId,0,0)))

              			perror("shmat");

       			};



			/* destructor function */

       			~message() {};



			/* check message queue open status */

       			int good() { return (shmId >= 0 && semId>=0) ? 1 : 0; };



			/* remove message queue */

			int rmQ() 

			{ 

            			if (shmdt((char*)msgPtr)<0) perror("semdt");

            			if (!semctl(semId,0,IPC_RMID,0) && !shmctl(shmId,IPC_RMID,0))

               				return 0;

            			perror("shmctl or semctl"); 

            			return -1;

       			};

             

       			/* send a message */

       			int send( const void* buf, int size, int type) 

			{

            			int server = (type > 99);

            			getsem(server ? SERVER_GET_MEM : CLIENT_GET_MEM);

            			memcpy(msgPtr->mtext,buf,size);

            			msgPtr->mtext[size] = `\0';

            			msgPtr->mtype = type;

            			getsem(server ? SERVER_SND_RPY : CLIENT_SND_REQ); 

            			return 0;

       			};     

			/* receive a message */

       			int rcv( void* buf, int size, int type, int* rtype) 			

			{

            			int server = (type < 0);

            			getsem(server ? SERVER_RCV_REQ : CLIENT_RCV_RPY); 

            			memcpy(buf,msgPtr->mtext,strlen(msgPtr->mtext)+1);

            			if (rtype) *rtype = msgPtr->mtype;

            			if (!server) getsem(RESET_SEM); 

            			return strlen(msgPtr->mtext);

       			};     

	}; 	/* message */



	#endif

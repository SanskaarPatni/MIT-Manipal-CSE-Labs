	#ifndef MESSAGE4_H

	#define MESSAGE4_H



	#include <strstream.h>

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <fcntl.h>
	#include <memory.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/mman.h>
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

      			int 	semId;

      			struct mgbuf  *msgPtr;

      			enum ipc_op { 		RESET_SEM, CLIENT_GET_MEM, 

						CLIENT_SND_REQ, SERVER_RCV_REQ, 

             					SERVER_GET_MEM, SERVER_SND_RPY, 

					CLIENT_RCV_RPY 	};

    		public:



       			/* try to change semaphores' values */

       				void getsem( enum ipc_op  opType ) 

			{

           			static struct sembuf  args[2] = { {SEM_RD}, {SEM_WR} };

           			switch (opType) 								{

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

							args[SEM_RD].sem_op = 1,

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

           		char mfile[256], fillchr='\0';

           		ostrstream(mfile,sizeof mfile) << "FOO" << key << '\0';

           		int fd =open(mfile,O_RDWR,0);

           		if (fd==-1) {	/* a new file */

			if ((fd=open(mfile,O_RDWR|O_CREAT|O_TRUNC,0777))==-1)

                  			perror("open");

               			else 			{

                   				/* zero fill the file for mmap to work. 

					This is system dependent */

                  				for (int i=0; i < SHMSIZE; i++) write(fd, &fillchr, 1);

                  				if ((semId=semget(key, SEMSIZE, IPC_CREAT|0666))==-1)

                      					perror("semget");

                  				else getsem(RESET_SEM);  // initialize a new semaphore set

               			}

           		} 

		else	{	 /* connect to an existing entry */

		if ((semId=semget(key, 0, 0))==-1) perror("semget");

		if ((msgPtr=(struct mgbuf*)mmap(0, SHMSIZE, PROT_READ | 

			PROT_WRITE, MAP_SHARED, fd,0))				== MAP_FAILED)

		perror("mmap");

           		else close(fd); 

		}

		};



		/* destructor function */

       			~message() {};



			/* check message queue creation status */

       			int good() { return (semId>=0) ? 1 : 0; };



			/* remove message queue */

       			int rmQ() 

			{ 

			if (!semctl(semId,0,IPC_RMID,0) && 

			!munmap((caddr_t)msgPtr,SHMSIZE))

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

            			msgPtr->mtext[size] = '\0';

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

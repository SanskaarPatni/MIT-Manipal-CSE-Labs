	#ifndef MESSAGE5_H

	#define MESSAGE5_H



	/* specify the following source code is POSIX.1b compliant */

	#define 		_POSIX_C_SOURCE 			199309L

	#include <strstream.h>
	#include <stdio.h>
	#include <memory.h>
	#include <unistd.h>
	#include <string.h>
	#include <limits.h>
	#include <sys/stat.h>
	#include <semaphore.h>
	#include <sys/mman.h>



	/* common declarations for daemon/server process */

	enum { MSGKEY=186, MAX_LEN=256, MAX_MSG=20 };

	enum { LOCAL_TIME=1, UTC_TIME=2, QUIT_CMD=3, ILLEGAL_CMD=4 };



	/* data record for one message */
	struct mgbuf 
	{
		long   		mtype;		// msg type
    		char   		mtext[MAX_LEN];		// msg text
	};



	/* data record for one shared memory region */
	struct shm_header 
	{
       		sem_t   	semaphore;		// semaphore
       		struct  mgbuf   msgList[MAX_MSG];		// msg. list

	};



	/* message class */

	class message 
	{
   		private:
        		struct shm_header	*memptr;
        		sem_t          		*sem_id;
        		char           		mfile[256];

      		enum ipc_op { GET_MEM, SND_RPY, RCV_REQ, RESET_SEM };

   		public:

		/* constructor function */

       		message( int key ) 
		{
			/* create a shared memory region */

            		ostrstream(mfile,sizeof mfile) << "FOO" << key << '\0';

			int fd = shm_open(mfile, O_CREAT|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO);

       			if (fd==-1) { perror("shm_open"); return; }

       			(void)ftruncate(fd,sizeof(struct shm_header));


			/* map shared memory to a process address space */
       			if ((memptr=(struct shm_header*)mmap(0, sizeof(struct shm_header), 
					PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))
					== MAP_FAILED) 			{

				perror("mmap");

                		return;

       			}


       			close(fd); 



			/* create a semaphore in the shared memory region */

            		sem_id = (sem_t*)&memptr->semaphore;

            		if ((sem_init(sem_id, 1, 1))==-1) perror("sem_init");



            		/* initialize msg list to be empty */

            		for (int i=0; i < MAX_MSG; i++) 
				memptr->msgList[i].mtype = INT_MIN;

		};



       		/* destructor function: unmap shared memory from process */
       		~message() { munmap(memptr, sizeof(struct shm_header)); };



        	/* check share memory creation status */
		int good() { return (memptr) ? 1 : 0; };



        	/* remove shared memory and semaphore */
 		int rmQ() 
		{ 

             		if (sem_destroy(sem_id)==-1) perror("sem_destroy");

             		if (shm_unlink(mfile)==-1) perror("shm_unlink");

             		return munmap(memptr, sizeof(struct shm_header));

        	};



		/* try to change semaphore's value */

       		void getsem( enum ipc_op  opType ) 
		{

          		switch (opType) 			{
              			case GET_MEM:  

              			case RCV_REQ:  

                     			if (sem_wait(sem_id)==-1) perror("sem_wait");

 		     			break;

              			case SND_RPY:  

              			case RESET_SEM:  

                     			if (sem_post(sem_id)==-1) perror("sem_post");

 		     			break;

       			}

       		};   /* getsem */



       		/* send a message to message queue*/

       		int send( const void* buf, int size, int type) 	
		{

             		getsem(GET_MEM);					// acquire semaphore

             		for (int i=0; i < MAX_MSG; i++) 

                 		if (memptr->msgList[i].mtype==INT_MIN) 					{

					/* find an empty slot in message queue to store msg */

		                    	memcpy(memptr->msgList[i].mtext, buf, size);

               		     		memptr->msgList[i].mtext[size] = '\0';

                    			memptr->msgList[i].mtype       = type;

		                    	break;

               			}

             		if (i >= MAX_MSG) 		{		// msg queue is full

				cerr <<  "Too many messages in the queue!\n";

               			return -1;				// return failure

             		}

             		getsem(SND_RPY);				// release semaphore

             		return 0;					// return OK

       		};   /* send */  



       		/* receive a message */
       		int rcv( void* buf, int size, int type, int* rtype) 	
		{

             		do 	 {

               			getsem(RCV_REQ); 				// acquire semaphore

               			int lowest_type = -1;

               			for (int i=0; i < MAX_MSG; i++) 					{

                  			if (memptr->msgList[i].mtype==INT_MIN) continue; 


						/* done if type==0 or type matches msg. type */

               					if (!type || type==memptr->msgList[i].mtype) break;

				
						/* if type < 0 find the lowest msg type < type */

                  				if (type < 0 && -type >= memptr->msgList[i].mtype)

                     					if (lowest_type==-1 || (memptr->msgList[i].mtype <

                              						memptr->msgList[lowest_type].mtype))

                        					lowest_type = i;

              				}

              				if (i < MAX_MSG || lowest_type !=-1) { 				// found one msg

						if (lowest_type!=-1) i = lowest_type;

						/* copy msg text and type to caller's variables */

               					memcpy(buf,memptr->msgList[i].mtext,

						strlen(memptr->msgList[i].mtext)+1);

               					if (rtype) *rtype = memptr->msgList[i].mtype;

						/* mark queue slot as empty */

               					memptr->msgList[i].mtype = INT_MIN;

            	 				getsem(RESET_SEM); 			// release semaphore

            	 				return strlen((char*)buf);			// return msg. size

					}
	
					getsem(RESET_SEM); 				// release semaphore

              				sleep(1);				// sleep for 1 second

             			} while(1);					// check queue again

		}; 	/* rcv */

	}; /* message */

	#endif

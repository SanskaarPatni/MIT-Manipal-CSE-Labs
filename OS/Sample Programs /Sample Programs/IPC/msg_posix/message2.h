	#ifndef MESSAGE2_H
	#define MESSAGE2_H

	#include <stdio.h>
	#include <memory.h>
	#include <sys/ipc.h>
	#include <mqueue.h>				// use POSIX.1b messages APIs


	/* common declarations for daemon/server process */

	enum { MSGKEY=186, MAX_LEN=256, ILLEGAL_CMD = 4};

	enum { LOCAL_TIME = 1, UTC_TIME = 2, QUIT_CMD = 3 };



	struct mgbuf

	{

    		long   		mtype;

    		char   		mtext[MAX_LEN];

	};

	/* POSIX.1b message class */

	class message 

	{

    		private:

      		mqd_t    msgId;		// message queue handle

      		struct mgbuf mObj;

    		public:

		/* System V compatible constructor function */

		message( int key ) 

		{

           			char name[80];

           			sprintf(name,"/MQUEUE%d",key);

           			if ((msgId=mq_open(name,O_RDWR|IPC_CREAT,0666,0))==(mqd_t)-1)

               				perror("mq_open");

       		};



		/* POSIX.1b style constructor function */

		message( const char* name ) 

		{

			if ((msgId=mq_open(name,O_RDWR|IPC_CREAT,0666,0))==(mqd_t)-1)

               				perror("mq_open");

       		};

		/* destructor function */

       		~message() {  (void)mq_close( msgId); };



		/* check queue open status */

       		int good() { return (msgId >= 0) ? 1 : 0; };



		/* remove message queue */

       		int rmQ() 

		{

            			return mq_close( msgId ); 

       		};



      		/* send a message */

      			int send( const void* buf, int size, int type) 

       			{

            				mObj.mtype = type;

            				memcpy(mObj.mtext,buf,size);

            				if (mq_send(msgId,(char*)&mObj,size,type)) 				{ 

                					perror("mq_send");

                					return -1;

            				};

            				return 0;

       			};     



       			/* receive a message */

       			int rcv( void* buf, int size, int type, unsigned* rtype) 

       			{

            				struct mq_attr attrv;

            				if (mq_getattr(msgId,&attrv)==-1) 					{

               					perror("mq_getattr"); 

               					return -1;

            				}

            				if (!attrv.mq_curmsgs) return -1; 		// no messages



            				int len = mq_receive(msgId,(char*)&mObj,MAX_LEN,rtype); 

            				if (len < 0) {

               					perror("mq_receieve");

               					return -2;

            				}



            				if (type && ((type > 0 && type!=*rtype) || 

                         					(type < 0 && -type < *rtype))) 				{

                					mq_send(msgId, (char*)&mObj, len, *rtype );

                					return -3;                  	// not the requested type

            				}

            				memcpy(buf,mObj.mtext,len);

            				return len;

       			};     

		};

		#endif				/* MESSAGE2_H */

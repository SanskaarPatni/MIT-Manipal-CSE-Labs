	#include <strstream.h>
	#include <string.h>
	#include "message.h"

	int main() 

	{

   		int      cmdId, pid;

				while (getpid() < 100) 

       		switch (pid=fork()) 		{		// make sure client PID > 99

           		case -1: 	perror("fork"), exit(1);

           		case 0:  	break;

           		default: 	waitpid(pid,0,0); exit(0);

				}



				cout << "client: start executing...\n";



   		message mqueue(MSGKEY);		// create a message object

   		if (!mqueue.good()) exit(1);		// quit if queue open fails

		char procId[256], buf2[256];

		ostrstream(procId,sizeof(procId)) << getpid() << '\0';

		do 		{

     		/* Get a cmd from the standard input */

      		cout << "cmd> " << flush;	// print an input prompt

      		cin >> cmdId;	// get a command from a user

     		cout << endl;	// force a <CR> at console

      		if (cin.eof()) break;  	// exit if EOF 



      		/* check cmd is valid */

      		if (!cin.good() || cmdId < 0 || cmdId > 99) 			{

         			cerr << "Invalid input: " << cmdId << endl; continue;

      		}

         		/* send request to daemon */

         		if (mqueue.send(procId,strlen(procId),cmdId)) 

            				cout << "client: " << getpid() << " msgsnd error\n";



         		else if (cmdId==QUIT_CMD) break; 		/* exit on QUIT_CMD */ 



         		/* read request from daemon */

         		else if (mqueue.rcv(buf2,sizeof(buf2),getpid(),0)==-1)

            				cout << "client: " << getpid() << " msgrcv error\n";



         		/* print server's response data */

         		else cout << "client: " << getpid() << "  " << buf2 << endl;



		} while (1);  /* loop until EOF */



   		cout << "client: " << getpid() << " exiting...\n" << flush;

		return 0;

	}

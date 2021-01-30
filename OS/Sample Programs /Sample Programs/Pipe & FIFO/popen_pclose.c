#include <stdio.h>

main()
{
  	FILE *fp;
  	char line[130];			/* line of data from unix command*/
   
  	fp = popen("ls -l", "r");		/* Issue the command.		*/

					/* Read a line			*/
  	while ( fgets( line, sizeof line, fp))
  	{
    		printf("%s", line);
  	}
  	pclose(fp);
}
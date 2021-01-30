#include <unistd.h>
#include <stdio.h>

int main()
{
    	char buf[4];
    	FILE* f = fopen("/dev/zero", "r");
    	close(fileno(f));  /* Evil: closing f's underlying file descriptor! */
    	fread(buf, 1, 4, f);  /* Ouch: Try, read four bytes into buf.*/
    	printf("%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3]);
    	return 0;
}



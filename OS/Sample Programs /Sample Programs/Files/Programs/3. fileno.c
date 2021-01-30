#include <stdio.h>
 
int main (void)
{
   	FILE *fp;
   	int result;
 
   	fp = fopen ("stderr","w");
 
   	result = fileno(fp);
   	printf("The file handle associated with stderr is %d.\n", result);
   	return 0;
 
}

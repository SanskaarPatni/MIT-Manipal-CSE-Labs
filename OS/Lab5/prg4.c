#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	int num;
	int num1=0;
	fptr = fopen("example.bin","wb+");
   printf("Enter 4 binary numbers\n");
	for(int i=1;i<=4;i++)
   {
      scanf("%d",&num);
    	fwrite(&num, sizeof(int), 1, fptr); 
   }
   printf("Write finished!! \n");
   fclose(fptr);
	fptr = fopen("example.bin","rb");
	for(int i=1;i<=4;i++)
   {
      fread(&num1, sizeof(int), 1, fptr); 
      printf("%d\n",num1);
   }   	
   printf("Read finished!! \n");
}
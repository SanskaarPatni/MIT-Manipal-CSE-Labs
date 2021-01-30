#include<stdio.h>
#include<unistd.h>
int main()
{
	vfork();
	printf("Hello\n");
}

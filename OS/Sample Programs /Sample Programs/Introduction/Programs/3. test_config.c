#define _POSIX_SOURCE
#define _POSIX_c_SOURCE
#include<iostream>
#include<unistd.h>
#include<stdio.h>
using namespace std;

int main()
{
	int res;
	if((res=sysconf(_SC_OPEN_MAX))==-1)
		perror("sysconf");
	else 
		cout<<"OPEN_MAX :"<<res<<endl;

	if((res=pathconf("/",_PC_PATH_MAX))==-1)
		perror("pathconf");
	else 
		cout<<"Max pathname:"<<(res+1)<<endl;
		
	if((res=fpathconf(0,_PC_CHOWN_RESTRICTED))==-1)
		perror("fpathconf");
	else
		cout<<"chown_restricted for stdin:"<<res<<endl;

	return 0;
}


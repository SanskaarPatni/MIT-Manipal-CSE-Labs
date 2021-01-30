#define _POSIX_SOURCE
#define _POSIX_c_SOURCE
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	#ifdef _POSIX_VERSION
		cout<<"System conforms to POSIX"<<_POSIX_VERSION<<endl;
	#else
		cout<<"_POSIX_VERSION is undefined\n"
	#endif 
	return 0;
}
 

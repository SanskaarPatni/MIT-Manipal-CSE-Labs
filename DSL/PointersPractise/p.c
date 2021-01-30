#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sample{
	char name[90],*str;
};
int main(){
struct sample s1={"Udupiaaa","Manipal"};
printf("%s\n",(s1.str+1)+1 );
printf("%c\n",*(s1.str+4) );
printf("%ld",sizeof(s1.name));
printf("%ld",strlen(s1.name));
printf("%s",s1.name);
return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void copy(char a[],char b[],int l){
	b[l]=a[l];
	if(a[l]=='\0')
	{   
		b[l]='\0';
		return;
	}
	else 
		copy(a,b,++l);
}
int main()
{
	char s1[100];
	scanf("%[^\n]",s1);
printf("Length of array is %d",strlen(s1));
	/*char* s1=(char *) calloc(n,sizeof(char));
	for(int i=0;i<n;i++){
	scanf("%c",&s1[i]);
}s1[i]!='\0'*/
	for(int i=0;i<strlen(s1);i++){
	printf("%c",s1[i]);
}
printf("\n");
	char s2[strlen(s1)];
	copy(s1,s2,0);

    printf("%s\n",s1);
    printf("%s\n",s2);
}

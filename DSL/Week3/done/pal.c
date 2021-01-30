#include<stdio.h>
int pal(char s[],int l,int n)
{
	if(s[l]!=s[n-l-1])
	{
		return 0;
	}
	else
	{
		if(l==(n/2))
		{
			return 1;
		}
		return (pal(s,++l,n));
	}
}
int main(){
	printf("Enter limit for string:\n");
	int  n;
	scanf("%d",&n);
	char s1[n];
	scanf("%s",s1);
	puts(s1);
	int palin=pal(s1,0,n);
	if(palin==0){
		printf("Given string is not a palindrome");
	}
	else
	{
		printf("Given string is a palindrome");
	}
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void backwards(char c[],char chh[],int n){
int i=0;
chh[n-i-1]=c[i];
if(chh[i]=='\n')
{
	return;
}
else
{
	return backwards(c,chh,n);
}


}
int main(){
	int n;
	scanf("%d",&n);
	char ch[n];
	char chh[n];
	
	for(int i=0;i<n;i++){
		scanf("%c",&ch[i]);
	}

	void backwards(ch,chh);
	printf("%s\n",chh);
}

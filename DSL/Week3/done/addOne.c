#include<stdio.h>
int firstCapital(char str[],int l){
	if(str[l]>='A' && str[l]<='Z')
		return l;
	else
		return firstCapital(str,++l);

}

int main(){
    int n;
	printf("Enter length of string");
	scanf("%d",&n);
	char a[n];
	printf("Enter a string:\n");
	scanf("%s",a);
	int index=firstCapital(a,0);
	printf("First capital letter is found at %d which is %c\n",index+1,a[index]);
}
#include<stdio.h>
long fib(int n)
{
	if(n<=1){
		return n;
	}
	else{
		return (fib(n-1)+fib(n-2));
	}
}
int main(){
	printf("Enter the limit:\n");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long a=fib(i);
		printf("%li\n",a);
	}

return 0;

}
#include<stdio.h>
int largestt(int a[],int n){
	int large=a[0];
    int sec=a[0];
    for(int i=0;i<n;i++){
    if(a[i]>large){
    	sec=large;
    	large=a[i];
    }
    else if(a[i]>sec){
    	sec=a[i];

    } 

    }
    return sec;
}


int main(){
	int a[100],n;
	printf("Enter the value for n:\n");
	scanf("%d",&n);
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    int seclargest=largestt(a,n);
    printf("%d",seclargest);
}
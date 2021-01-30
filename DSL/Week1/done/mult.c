#include<stdio.h>
//ab toh yaad rhega ki jitna declare kiya hota hai 2d array ka utna hi column size should be there in function defination
void mult(int m,int n,int p,int q,int a[][10],int b[][10]){
	int k=0;
	/*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           printf("%d\t",a[i][j]);
           }
        printf("\n");
       }
       for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
           printf("%d\t",b[i][j]);
           }
        printf("\n");
       }*/
    if(n!=p){
		printf("Multiplication cannot be done"); 
     }
     else{
     	int c[m][q];
     	for(int i=0;i<m;i++)
     	{

     		for(int j=0;j<q;j++)
     		{
     			int sum=0;
     			for(int k=0;k<p;k++)
     			{
     				//sum=sum+a[i][k]*b[k][j];
     			    sum +=*(*(a+i)+k) * *(*(b+k)+j);
          }

     			c[i][j]=sum;

            }
	}
	printf("Matric formed by multiplication is :\n");
	for(int i=0;i<m;i++){
     		for(int j=0;j<q;j++){
     			printf("%d\t",c[i][j]);
}
printf("\n");
}
}
}
int main(){
  //static memory allocation
    int a[10][10],b[10][10],m,n,p,q;
    printf("Enter the value for m:\n");
	scanf("%d",&m);
	printf("Enter the value for n:\n");
	scanf("%d",&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           scanf("%d",&a[i][j]);
    }
}
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           printf("%d\t",a[i][j]);
           }
        printf("\n");
       }
     printf("Enter the value for p:\n");
	scanf("%d",&p);
	printf("Enter the value for q:\n");
	scanf("%d",&q);
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
           scanf("%d",&b[i][j]);
    }
}
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
           printf("%d\t",b[i][j]);
           }
        printf("\n");
       }

       mult(m,n,p,q,a,b);




}

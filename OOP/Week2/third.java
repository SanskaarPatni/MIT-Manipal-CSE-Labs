import java.util.Scanner;
class third{
public static void LSearch(int a[],int n,int num){
int pos=0;
for(int i=0;i<n;i++){
if(a[i]==num){
System.out.println("Number found at "+ (i+1)+" position");
}
}
}


public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter number of elements:");
int n=sc.nextInt();
int a[]=new int[n];

for(int i=0;i<n;i++){
a[i]=sc.nextInt();
}
System.out.println("Enter number to be searched:");
int num=sc.nextInt();
LSearch(a,n,num);
}
}

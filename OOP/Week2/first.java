import java.util.Scanner;
class first{
public static void ascending(int a[],int n){
int temp;
for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(a[j]>a[j+1]){
      temp=a[j];
       a[j]=a[j+1];
      a[j+1]=temp;
    }
} 
}
for(int i=0;i<n;i++){
System.out.println(a[i]);
}
}
public static void descending(int a[],int n){
int temp;
for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(a[j]<a[j+1]){
      temp=a[j];
       a[j]=a[j+1];
      a[j+1]=temp;
    }
} 
}
for(int i=0;i<n;i++){
System.out.println(a[i]);
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
System.out.println("Enter 0 for ascending and 1 for descending");
int b=sc.nextInt();
if(b==0)
{
ascending(a,n);
}
else{
descending(a,n);
}
}
}





import java.util.Scanner;
class second{
public static void delete(int a[],int n,int pos){
for(int i=pos;i<n-1;i++)
{
a[i]=a[i+1];

}
for(int i=0;i<n-1;i++){
System.out.println(a[i]);
}

}
public static void insert(int a[],int n,int pos,int num){
for(int i=n-1;i>=pos;i--)
{
a[i]=a[i-1];

}
a[pos]=num;
for(int i=0;i<n;i++){
System.out.println(a[i]);
}


}
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter number of elements:");
int n=sc.nextInt();
int a[]=new int[n+1];

for(int i=0;i<n;i++){
a[i]=sc.nextInt();
}
System.out.println("Enter position: ");
int pos=sc.nextInt();
System.out.println("Enter 0 for insertion and 1 for deletion");
int b=sc.nextInt();
if(b==0)
{
System.out.println("Enter number to be inserted");
int num=sc.nextInt();
insert(a,n+1,pos-1,num);
}
else{
delete(a,n,pos-1);
}
}
}

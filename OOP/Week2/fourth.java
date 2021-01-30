import java.util.Scanner;
class fourth{
public static void MatAdd(int m,int n,int a[][],int b[][]){
int c[][]=new int[m][n];
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
     c[i][j]=a[i][j]+b[i][j];
}


}
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
    System.out.print(c[i][j]+" ");
}
System.out.println();

}
}

public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter number of rows for a:");
int m=sc.nextInt();
System.out.println("Enter number of columns for a :");
int n=sc.nextInt();
System.out.println("Enter number of rows for b:");
int p=sc.nextInt();
System.out.println("Enter number of columns for b:");
int q=sc.nextInt();
int a[][]=new int[m][n];

for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
     a[i][j]=sc.nextInt();
}
}
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
     System.out.print(a[i][j]+" ");
}
System.out.println();
}

int b[][]=new int[p][q];

for(int i=0;i<p;i++){
  for(int j=0;j<q;j++){
     b[i][j]=sc.nextInt();
}
}
for(int i=0;i<p;i++){
  for(int j=0;j<q;j++){
     System.out.print(b[i][j]+" ");
}
System.out.println();
}
if(m==p && n==q){
  MatAdd(m,n,a,b);
}
}
}

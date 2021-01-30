import java.util.Scanner;
class Sample4{
public static double fact(int n){
/*if(n<0){
System.out.println("Factorial cannot be calculated for negative numbers");
}*/
double f=1;
if(n==0){
f=1;
}
else
{
for(int i=1;i<=n;i++){
f=f*i;
}
}

return f;

}

public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
   System.out.println("Type in a number");
  int a=sc.nextInt();
  double x=fact(a);
  
    System.out.println("Type in a value for r");
    int r=sc.nextInt();
    double y=fact(r);
    double z=x/(y*fact(a-r));
    System.out.println("The Value of nCr is "+z);
}
}

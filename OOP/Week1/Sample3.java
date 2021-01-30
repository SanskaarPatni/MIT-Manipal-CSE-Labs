import java.util.Scanner;
class Sample3{

public static void roots(int a,int b,int c){
int d=b*b - 4*a*c;
int k;
if(d>0){
 k=1;
 }
else if(d<0){
 k=2;
}
else{
 k=3;
}
switch(k)
{
case 1:
double x1=(-b+Math.sqrt(d))/(2*a);
double x2=(-b-Math.sqrt(d))/(2*a);
System.out.println("The two roots are "+ x1 +"and "+x2);
break;
case 2:
System.out.println("The two roots are imaginary");
break;
case 3:
x1=(-b)/(2*a);
x2=(-b)/(2*a);
System.out.println("The two roots are "+ x1 +"and "+x2);
break;

}

}

public static void main(String args[]){
Scanner sc=new Scanner(System.in);
System.out.println("Enter three values for a,b and c");
int a=sc.nextInt();
int b=sc.nextInt();
int c=sc.nextInt();
roots(a,b,c);
}

}

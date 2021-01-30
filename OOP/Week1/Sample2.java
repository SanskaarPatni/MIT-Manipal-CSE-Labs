import java.util.Scanner;
class Sample2{

static double largest(double a,double b,double c){
if(a>b){
if(a>c){
return a;
}
else{
return c;
}
}
else{
if(b>c){
return b;

}
else{
return c;
}
}
}
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
double x=sc.nextDouble();
double y=sc.nextDouble();
double z=sc.nextDouble();
//double x=200,y=305.60,z=115.5;
double large=largest(x,y,z);
System.out.println("Largest number is "+ large);
}


}

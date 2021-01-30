import java.util.Scanner;
class MainComplex{
public static void main(String args[]){
	Complex comp1=new Complex();
	Scanner sc=new Scanner(System.in);
	Complex comp2=new Complex();
	double a=sc.nextDouble();
	double b=sc.nextDouble();
	comp1.Assign(a,b);
	comp1.Display();
	a=sc.nextDouble();
	b=sc.nextDouble();
	comp2.Assign(a,b);
	comp2.Display();
	Complex af=new Complex();
	af=comp1.AddComplex(comp2);
	System.out.println("Complex number after adding "+af.a+" + "+"i"+af.b);
	comp1.Subtract(comp2);
}
}
class Complex{
	double a;
	double b;

void Assign(double x,double y){
	a=x;
	b=y;
}
void Display(){
	System.out.println(a +" + i"+b);
	
}
Complex AddComplex(Complex f){
Complex add=new Complex();
add.a=f.a + a;
add.b=f.b + b;
return add;
}
void Subtract(Complex f){
	Complex sub=new Complex();
sub.a=f.a - a;
sub.b=f.b - b;
System.out.println("Complex number after subtracting "+Math.abs(sub.a)+" + "+"i"+Math.abs(sub.b));
	
}
	

}
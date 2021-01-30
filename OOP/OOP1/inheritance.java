import java.util.*;
/*abstract class  A{
 	int a;
 	A(int x){
 		this.a=x;
 	}
 	abstract void m();
	
}
abstract class B extends A{
	int a;
	B(int x,int y){
		super(x);
		a=y;

	
}
	//void m(){
 		//System.out.println("B ka a"+a);
 	
 	//}
 	void m1(){
 		System.out.println("Can A access this :");
 	}
}
class C extends B{
	int a;
	C(int x,int y,int z){
	super(x,y);
	this.a=z;
}
	void m(){
		//super.m();
 		System.out.println("C ka a"+a);
 	}
	
}
class inheritance{
	public static void main(String args[]){
		A ap=new B(11,11);
		ap.m1();
	}
}*/
class A{
A(){

System.out.println("fuckk");
	m1();
}
void m1(){
 	System.out.println("yoo");
}
}
class B extends A{
	void m1(){
		System.out.println("yo1");
	}
}
class C extends B{
	void m1(){
		System.out.println("yo2");
	}
}
class inheritance{
 public static void main(String[] args) {
 	B a=new C();
 	a.m1();
System.out.println();
 	int $1=8080;
 	int p=8080%256;
 	byte x=(byte)$1;
 	System.out.println(p +" "+$1 +"  "+x);
	System.out.println((char)('a'+1));	
	}
}

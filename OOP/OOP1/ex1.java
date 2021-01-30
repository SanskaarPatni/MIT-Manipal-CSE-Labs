import java.util.Scanner;
class ex2{
	int x;
	void m(){};

}
class A extends ex2{
	void m(int x){System.out.println("IT CANNN"+x);}
}
class ex1{
	public static void main(String args[]){
ex2 b=new ex2();
ex2 c=b;
ex2 f=new A();
f.m(10);
System.out.println(b.x);
b =null;
System.out.println(c.x);
int y=0;
System.out.println(y);
String str1="yo";
String str=new String (str1);
System.out.println(str);	}
}
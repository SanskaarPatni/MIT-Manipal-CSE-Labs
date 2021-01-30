class Base{
	int v=0;
	Base(){
//this also call B ka addV method not iss class ka when an object of type B is made
		addV();}
	void addV(){
		v+=10;
	}
	int getV(){
		return v;
	}
}
class B extends Base{
	B(){
		addV();
	}
	void addV(){
		v+=20;
	}
}
class C extends B{
	C(){
		addV();
	}
	void addV(){
		v+=30;
	}
}
public class sess{
	public static void main(String args[]){
		Base a=new Base();
	Base b=new B();
	B c=new C();
	C c1=new C();

	System.out.println(a.getV());
	System.out.println(b.getV());
	System.out.println(c.getV());
	System.out.println(c1.getV());
	}
}

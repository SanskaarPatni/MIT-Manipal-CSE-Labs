interface yo
{
	void callmetoo();

}
class A implements yo{
	void callme(){
	System.out.println("This is a concrete method.");
}

// concrete methods are still allowed in abstract classes

public void callmetoo() {

System.out.println("This is a concrete method."); } }

class B extends A {
void callmetoos() {

System.out.println("This is a concrete method in B."); }

public void callme() {

System.out.println("B's implementation of callme."); } }

class AbstractDemo {

public static void main(String args[]) {
	yo Y=new A();
	Y.callmetoo();

B b = new B();

b.callme();

b.callmetoo(); }

} 
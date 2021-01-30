class A{
	public void meth(){
		System.out.println("IS THIS POSSIBLE");
	}
	
}
class B extends A{
	public void meth(){
		System.out.println("IS THIS POSSIBLE");
	}
}
class inher{
	public static void main(String args[]){
		A b=new B();
	}
}
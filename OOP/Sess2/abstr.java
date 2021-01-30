interface ranom{
 final static void  f(int x){
	System.out.println("");
}
	int y=10;

}
class A implements ranom{
int y=11;
public void f(int x){
	
}
}
class abstr{
	public static void main(String args[]){
		A b=new A();
		System.out.println(b.y);
	}
}
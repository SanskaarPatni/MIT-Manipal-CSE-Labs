class tryy{
public static void main(String args[]){
	System.out.println("A"+(4*12));
	try{
		System.out.println("Hello "+" \n"+ 1*0);
	}
	catch(ArithmeticException e){
		System.out.print("World");
	}

}
}
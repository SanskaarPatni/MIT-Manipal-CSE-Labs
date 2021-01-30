class MyException extends Exception { }
class ExceptionDemo
{ public static void main(String args [])
{ int a=-10;
try { if ( a<0)
	throw new MyException();
	//return;
//System.exit(0); 
}
catch(MyException me)
{
	 System.out.println("From catch block");
}
finally { System.out.println("From finally block"); }
} }
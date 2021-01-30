import java.util.Scanner;
class finallycheck{
	public static void main(String args[]){
		for(int i=0;i<3;i++){
			usefinally.genexc(i);
			System.out.println("");
		}
	}
}
class usefinally{
	static void genexc(int what){
		int t;
		int []a=new int[2];
		System.out.println("Recieved "+what);
		try{
			switch(what){
				case 0:
				t=10/what;
				break;
				case 1:
				t=a[4];
				break;
				case 2:return;
			}
		}
		catch(ArithmeticException e){
			System.out.println("Divide By zero");
			return ;
			//System.exit(0);
		}
		catch(ArrayIndexOutOfBoundsException e){
		System.out.println("Array Index out of Bounds");
		return;
	}
	finally{
	System.out.println("Leaving try");
	}
}
}
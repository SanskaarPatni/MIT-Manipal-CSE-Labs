import java.util.Scanner;
class fuckAllException extends Exception{
	fuckAllException(String msg)
	{
		super(msg);
	}
}
class tp{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();

		try{
			if(a>2)
				throw new fuckAllException("jhing jhing");
			else{
				System.out.println("number is less than two");
			}	
							System.out.println("Life must moce on");

		}

		catch(fuckAllException as)
		{
			System.out.println(as);
		}

	
	}
}
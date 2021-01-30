import java.util.*;
class Phone{
	String brand;
	int memCapacity;
	Phone(String Brand,int MemCap){
		brand=Brand;
		memCapacity=MemCap;
	}
	interface Callable{
		public void makeAudioCall(String cellNum);
		public void makeVideoCall(String cellNum);

	} 
}
class BasicPhone extends Phone implements Phone.Callable{
	BasicPhone(String Brand,int MemCap){
		super(Brand,MemCap);

	}
	public void makeAudioCall(String cnum){
		System.out.println("Make an Audio call to "+ cnum);
	}
	public void makeVideoCall(String cnum){
		System.out.println("Im a basic phone dont have video calling features");
	}

}
class SmartPhone extends Phone implements Phone.Callable{
	SmartPhone(String Brand,int MemCap){
		super(Brand,MemCap);
	}
	public void makeVideoCall(String cnum){
		System.out.println("Make an Video call to: " + cnum);
	}
	public void makeAudioCall(String cnum){
		System.out.println("Make an Audio call to "+ cnum);
	}
}
class Phonetest{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("1.Use Basic Phone.\n2.Use Smart Phone: ");
		int num=sc.nextInt();
		System.out.println("Enter phone brand and its Memory Capacity ");
		String s=sc.nextLine();
		sc.next();
		int mem=sc.nextInt();
		sc.nextLine();
		System.out.println("Enter Phone number who has to  be contacted:");
		String phone=sc.nextLine();

		if(num==1){
		System.out.println("Inside Basic Phone.\n1.Make an Video call.\n2.Make an Audio call.");
		int t=sc.nextInt();
		BasicPhone A=new BasicPhone(s,mem);
		if(t==1){

			A.makeVideoCall(phone);
		}
		if(t==2){
			A.makeAudioCall(phone);

		}
	
	}
		if(num==2){
		System.out.println("Inside Smart Phone.\n1.Make an Video call.\n2.Make an Audio call.");
	    int t=sc.nextInt();
		SmartPhone B=new SmartPhone(s,mem);
		
		if(t==1){
				B.makeVideoCall(phone);
		}
		if(t==2){
			B.makeAudioCall(phone);

		}
}
}
}

import java.util.*;
class SeatsFilledException extends Exception{
	SeatsFilledException(String s){
	super(s);
}
}

class Student{
	int reg_no;
	String name;
	int year;
	Student(String nam,int y,int reg){
		name=nam;
		year=y;
		reg_no=y*100+reg;
	}
	void check(int reg)throws SeatsFilledException{
		if(reg>25){
			throw new SeatsFilledException("Seats are filled.Sorry try next year");
		}
		else
		{
			System.out.println("Registration accepted.");
		}
	}

void Display(){
	System.out.println("Student Details\nName: "+ name+"\nRegistration number: "+reg_no);

}
}
class TestStudent{
	public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter student name\nYear of joining(last two digits)\nEnter last two digits of registration number");
	String N=sc.nextLine();
	int y=sc.nextInt();
	int p=sc.nextInt();
	Student S=new Student(N,y,p);
	S.Display();
	try{
		S.check(p);
	}
	catch(SeatsFilledException sp){
		System.out.println(sp);

	}

	}
}
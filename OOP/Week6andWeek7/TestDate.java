import java.util.*;
class InvalidDateException extends Exception{
	InvalidDateException(String s){
	super(s);
}
}
class InvalidMonthException extends Exception{
	InvalidMonthException(String s){
	super(s);
}
}
class currentDate{
	int day;
	int month;
	int year;
	Scanner sc=new Scanner(System.in);
	void createDate()throws InvalidDateException,InvalidMonthException{
		currentDate c=new currentDate();
		System.out.println("Enter day,month and year respectively");
		c.day=sc.nextInt();
		c.month=sc.nextInt();
		c.year=sc.nextInt();
		
		int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(c.year%400==0){
			a[1]=29;
		}
		if(c.month>12 || c.month<1){
		throw new InvalidMonthException("Month has to be in the range of 1-12");
		}

		if(c.day<1 ||c.day>a[c.month-1]){
		throw new InvalidDateException("Wrong date entered for the particular month");
		}
		else{
			System.out.println("Date Inputted is: "+c.day+"/"+c.month+"/"+c.year);
		}
	}
}
class TestDate{
	public static void main(String args[]){
		currentDate cd=new currentDate();
		try{
			cd.createDate();
		}
		catch(InvalidDateException e1){
			System.out.println(e1);
		}
		catch(InvalidMonthException e2){
			System.out.println(e2);
		}
	}
}


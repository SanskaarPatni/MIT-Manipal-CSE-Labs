import java.util.Scanner;
class MainTime{
	public static void main(String args[]){
		Time t1=new Time();
        Scanner sc=new Scanner(System.in);
        int hr=sc.nextInt();
        int min=sc.nextInt();
        int sec=sc.nextInt();
        t1.Assign(hr,min,sec);
        t1.Display();
        
        Time t2=new Time();
       
        hr=sc.nextInt();
        min=sc.nextInt();
        sec=sc.nextInt();
        t2.Assign(hr,min,sec);
        t2.Display();
        
        Time t=new Time();
        t=t1.Add(t2);
        t.Display();
        t=t1.Sub(t2);
        t.Display();
        t1.Equal(t2);
}
}
class Time{
	int hrs;
	int min;
	int sec;
void Assign(int x,int y,int z)
{
	hrs=x;
	min=y;
	sec=z;
}
void Display(){
	if(hrs<10){
		System.out.print("0"+hrs+":");
    }
    else{
    	System.out.print(hrs+":");
    }
	if(min<10){
		System.out.print("0"+min+":");
    }
    else{
    	System.out.print(min+":");
    }

	if(sec<10){
	System.out.println("0"+sec);
}
else
	System.out.println(+sec);
}
Time Add(Time j){
	Time latest=new Time();
	latest.sec=sec+j.sec;
	if(latest.sec>60){
		latest.sec=latest.sec -60;
		latest.min+=1;
	}
	latest.min=min+j.min;
	if(latest.min>60)
	{
		latest.min=latest.min-60;
		latest.hrs+=1;
	}
	latest.hrs=hrs+j.hrs;
	if(latest.hrs>24){
		latest.hrs=latest.hrs -24;
}
	return latest;
}
Time Sub(Time j){
	Time latest=new Time();
	latest.sec=Math.abs(sec-j.sec);
	latest.min=Math.abs(min-j.min);
	latest.hrs=Math.abs(hrs-j.hrs);
return latest;
}

void Equal(Time f){
	if(hrs==f.hrs && min==f.min && sec==f.sec){
		System.out.println("Two times are equal");

	}
	else{
		if(hrs>f.hrs){
			System.out.println("First one is bigger ");
	}
	else if(f.hrs>hrs){
		System.out.println("Second one is bigger");

	}
	else{
		if(min>f.min)
		{
			System.out.println("First one is bigger ");
		}
		else if(f.min>min){
		System.out.println("Second one is bigger");
	}
	else{
		if(sec>f.sec)
		{
			System.out.println("First one is bigger ");
		}
		else{
		System.out.println("Second one is bigger");


	}
	}
	}



}
}
}
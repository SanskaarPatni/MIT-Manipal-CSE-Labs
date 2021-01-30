import java.util.*;
interface Series{
	int getNext();
	void reset();
	void setStart(int x);
}
class ByTwos implements Series{
	int start;
	int val;
	ByTwos(){
		start=val=0;
	}
	public int getNext(){
		val+=2;
		return val;
	}
	public void reset(){
		val=start;
	}
	public void setStart(int x){
		start=x;
		val=x;
	}
}
class TestSeries{
	public static void main(String args[])
	{
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter starting value for the series");
	int t=sc.nextInt();
	ByTwos ob=new ByTwos();
	ob.setStart(t);
	System.out.println("Enter number of elements for the series:");
	int f=sc.nextInt();
	System.out.println("Series is:");
	System.out.print(t+" ");
	for(int i=0;i<f-1;i++){
		System.out.print(ob.getNext()+" ");
	}
}

}
import java.util.Scanner;
class Mythread extends Thread{
	Multi m;
	int x;
	Mythread(String name,Multi m1,int x){
		super(name);
		m=m1;
		this.x=x;
		start();
	}
	public void run(){
		m.multi(x);
	}
}
class Multi{
	synchronized void multi(int x)
	{
		try{
			for(int i=0;i<10;i++){
				System.out.println(x+"x"+(i+1)+"="+(x*(i+1)));
			}
		Thread.sleep(1000);
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}

	}
}
class multTest
{
	public static void main(String args[]){
		Multi m=new Multi();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter two elements whose multiplication table has to be found out(synchronized manner)");
		int a=sc.nextInt();
		int b=sc.nextInt();
		Mythread ob1=new Mythread("First",m,a);
		Mythread ob2=new Mythread("Second",m,b);
	}
}
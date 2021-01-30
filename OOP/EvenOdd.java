import java.util.*;
class EvenOrOdd{
	boolean valueSet=false;
	int eve=0;
	int odd=1;
	synchronized public void Even()
	{
		try{
		while(!valueSet)
		{
			wait();
		}
		}
		catch(InterruptedException ie){
			System.out.println(ie);
		}
		valueSet=false;
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
		System.out.println((eve));
		eve=eve+2;
		notify();
	}
	synchronized public void Odd()
	{
		try{
		while(valueSet)
		{
			wait();
		}
		}
		catch(InterruptedException ie){
			System.out.println(ie);
		}
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
		valueSet=true;
		System.out.println((odd));
		odd=odd+2;
		notify();
	}
}
class NewThread implements Runnable{
	Thread t;
	EvenOrOdd eo;
	NewThread(EvenOrOdd Eo,String name)
	{
		eo=Eo;
		t=new Thread(this,name);
		t.start();
	}
	public void run()
	{
		if(t.getName().equals("Even"))
		{
			for(;;)
			eo.Even();
		}
		else
		{
			for(;;)
			eo.Odd();
		}
	}
}
class EvenOdd{
	public static void main(String args[])
	{
	EvenOrOdd EO=new EvenOrOdd();
	NewThread t1=new NewThread(EO,"Even");
	NewThread t2=new NewThread(EO,"Odd");
	try
	{
		t1.t.join();
		t2.t.join();
	}
	catch(InterruptedException ie){
			System.out.println(ie);
	}

	}
}
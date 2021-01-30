import java.util.Scanner;
class functions{
	private int count;
	synchronized void printEven(){
			try{
			while(count>=5){
				System.out.println("Waiting for the decrement because "+count);
				wait();}
			}
			catch(InterruptedException e){
				System.out.println("Inturrepted");
			}
	        try{
				Thread.sleep(100);
			}
			catch(InterruptedException e){
				System.out.println("Inturrepted");
			}
			count++;
					System.out.println("Increment performed. New count "+count);
			notify();
		
	}

 synchronized void printOdd(){
 		try{
			while(count<=0){
				System.out.println("Waiting for the increment because "+count);
				wait();
			}
			}
			catch(InterruptedException e){
				System.out.println("Inturrepted");
			}
	        try{
				Thread.sleep(100);
			}
			catch(InterruptedException e){
				System.out.println("Inturrepted");
			}
			count--;
					System.out.println("Decrement performed. New count "+count);
			notify();
 }
		
}
class mythread implements Runnable{
	Thread thrd;
	boolean increment;
	 functions fnc;
	mythread(boolean b,functions fnc){
		increment=b;
		thrd=new Thread(this);
		this.fnc=fnc;
		thrd.start();
	}
	public void run(){
for(int i=0;i<10;i++)
		if(increment){
		fnc.printEven();
	//System.out.println("i "+i);
	}
	else{
		fnc.printOdd();
	
	//System.out.println("i "+i);
	}
	}

}
class evenodd2{
	public static void main(String args[])
	{
		functions F=new functions();
		mythread mt1=new mythread(true,F);
		mythread mt2=new mythread(false,F);
		try{
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException e){
			System.out.println("Main Thread Interrupted.");
		}
	}
	
}
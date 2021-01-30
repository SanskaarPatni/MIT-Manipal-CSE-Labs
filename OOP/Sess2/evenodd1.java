import java.util.Scanner;
class functions{
	void printEven(){
		for(int i=0;i<100;i++){
			if(i%2==0){
				try{
					Thread.sleep(1000);
				}
				catch(InterruptedException e){
					System.out.println("Inturrepted");
				}
			System.out.println(i);
		}

	}
}
 void printOdd(){
		for(int i=0;i<100;i++){
			if(i%2!=0){
				try{
					Thread.sleep(1000);
				}
				catch(InterruptedException e){
					System.out.println("Inturrepted");
				}

			System.out.println(i);
		}}
	}
}
class mythread implements Runnable{
	Thread thrd;
	functions fnc=new functions();
	mythread(String name,functions fnc){
		thrd=new Thread(this,name);
		this.fnc=fnc;
		thrd.start();
	}
	public void run(){
		if(thrd.getName().equals("Child1"))
		fnc.printOdd();
	else
		fnc.printEven();
	}

}
class evenodd1{
	public static void main(String args[])
	{
		functions F=new functions();
		mythread mt1=new mythread("Child1",F);
		mythread mt2=new mythread("Child2",F);
		try{
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException e){
			System.out.println("Main Thread Interrupted.");
		}
	}
	
}
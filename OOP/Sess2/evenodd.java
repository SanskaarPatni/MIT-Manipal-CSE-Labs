import java.util.Scanner;
class functions{
	void printEven(){
		for(int i=0;i<100;i++){
			if(i%2==0){
				try{
					Thread.sleep(100);
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
					Thread.sleep(100);
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
	functions fnc;
	mythread(String name,functions fnc){
		thrd=new Thread(this,name);
		this.fnc=fnc;
		thrd.start();
	}
	public void run(){
		fnc.printOdd();
		//fnc.printEven();
	}

}
class mythread1 implements Runnable{
	Thread thrd;
	functions fnc;
	mythread1(String name,functions fnc){
		thrd=new Thread(this,name);
		this.fnc=fnc;
		thrd.start();
	}
	public void run(){
		fnc.printEven();
	}

}
class evenodd{
	public static void main(String args[])
	{
		functions F=new functions();
		mythread mt1=new mythread("Child1",F);
		mythread1 mt2=new mythread1("Child2",F);
		try{
			mt1.thrd.join();
			mt2.thrd.join();
		}
		catch(InterruptedException e){
			System.out.println("Main Thread Interrupted.");
		}
	}
	
}

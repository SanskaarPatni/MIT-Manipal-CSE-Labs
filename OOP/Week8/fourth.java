class NewThread extends Thread{
	public void run(){
		System.out.println("The thread is running now");
		System.out.println("The priority is "+this.getPriority());
	}
}
class fourth{
	public static void main(String args[]){
		NewThread t1=new NewThread();
		NewThread t2=new NewThread();
		NewThread t3=new NewThread();
		t1.setPriority(1);
		t2.setPriority(2);
		t3.setPriority(3);
		try{
			t1.start();
			t1.join();
		
			t2.start();
			t2.join();
			
			t3.start();
			t3.join();
		}
		catch(InterruptedException e){
			System.out.println(e);

		}

	}
}
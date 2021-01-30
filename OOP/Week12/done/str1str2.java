import java.util.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
class ThinkTank{
	boolean valueSet=true;
	public synchronized void m1(String s1)
	{
		while(!valueSet)
		{
			try{
			wait();
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
		}
		System.out.print(s1+" ");
		valueSet=false;
		notify();
	}
	public synchronized void m2(String s2)
	{
		while(valueSet)
		{
			try{
			wait();
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
		}
		System.out.println(s2);
		valueSet=true;
		notify();
	}
}
class NewThread implements Runnable{
	Thread t;
	ThinkTank ttt;
	String names;
	String pe;
	NewThread(ThinkTank tt,String name,String yo){
		t=new Thread(this,name);
		ttt=tt;
		names=name;
		pe=yo;
		t.start();
	}
	public void run()
	{
		for(;;)
	if(t.getName()=="Thread1")
	{try{
		
Thread.sleep(1000);

	}
	catch(InterruptedException ie)
	{System.out.println(ie);
		
	}
		ttt.m1(pe);
	}
	else{
for(;;)
try{
		
Thread.sleep(1000);

	}
	catch(InterruptedException ie)
	{System.out.println(ie);
		
	}
		ttt.m2(pe);
	}
}
}

public class str1str2 extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		ThinkTank tt=new ThinkTank();
		FlowPane root=new FlowPane();
		root.setHgap(10);
		root.setVgap(10);
		TextField t1=new TextField();
		TextField t2=new TextField();
		Button B=new Button("Lets start multithreading");

		Scene myScene=new Scene(root,400,400);
		B.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				String s1=t1.getText();
				String s2=t2.getText();
				NewThread m1=new NewThread(tt,"Thread1",s1);
				NewThread m2=new NewThread(tt,"Thread2",s2);
				try{
				m1.t.join();
				m2.t.join();
				}
				catch(InterruptedException ie)
				{
					System.out.println(ie);
				}
			}

		});
		myStage.setScene(myScene);
		root.getChildren().addAll(t1,t2,B);
		myStage.show();

	}
}

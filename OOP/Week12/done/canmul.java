import java.util.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.scene.canvas.*;
class ThinkTank{
	GraphicsContext cgg;
	String s="";
	ThinkTank(GraphicsContext c)
	{
		cgg=c;
	}
	boolean valueSet=true;
	public void m1(String s1)
	{
		for(int i=0;i<3;i++){
			s=s+" "+s1;
			cgg.clearRect(0,0,400,400);
			cgg.fillText(s,35,20);
			
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
	
}
}
	public void m2(String s2)
	{

	for(int i=0;i<3;i++){
		s=s+" "+s2;
	
	try{
			Thread.sleep(1000);
		}
		catch(InterruptedException ie)
		{
			System.out.println(ie);
		}
}
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
	if(t.getName()=="Thread1")
	{
		ttt.m1(pe);
	}
	else{
		ttt.m2(pe);
	}
}
}

public class canmul extends Application
{
	GraphicsContext cg;
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		FlowPane root=new FlowPane();
		root.setHgap(10);
		root.setVgap(10);
		TextField t1=new TextField();
		TextField t2=new TextField();
		Button B=new Button("Lets start multithreading");
		Canvas c=new Canvas(400,400);
		cg=c.getGraphicsContext2D();
			ThinkTank tt=new ThinkTank(cg);
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
		root.getChildren().addAll(t1,t2,B,c);
		myStage.show();

	}
}
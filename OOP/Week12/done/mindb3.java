import javafx.application.*;
import javafx.scene.*;
import javafx.scene.canvas.*; 
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.geometry.*;
import javafx.event.*;
import java.util.Scanner;
interface GenInt<T>{
	void insertt(T data);
	T delete();
}
class Gen<T> implements GenInt<T>
{
	int n;
	T arr[];
	int f=-1;
	int r=-1;
	Gen(int n)
	{
		this.n=n;
		arr=(T[])new Object[n];
	}
	public void insertt(T data)
	{	
		if(r==n-1)
			System.out.println("Queue is full");
		else{
			if(f==-1)
			{
				f=0;
			}
			arr[++r]=data;
		}
	}
	public T delete()
	{
		T ret;
		if(f==-1)
		{
			System.out.printf("Queue is empty");
			return null;
		}
	
		
		else{
			ret=arr[f++];
			return ret;
		}
	}
}
public class mindb3 extends Application
{

	Label response;
	public void start(Stage myStage)
	{
		Scanner sc=new Scanner(System.in);
		Label response=new Label("Select which type of Generic Class is to be made");
		Separator sp=new Separator();
		sp.setPrefWidth(180);
		//ToggleGroup tg=new ToggleGroup();
		CheckBox StrinG=new CheckBox("String Queue");
		CheckBox Integerr=new CheckBox("Integer Queue");
		Label r2=new Label("Enter max size of Generic Queue");
		TextField t1=new TextField();
		Canvas c=new Canvas(400,400);
		GraphicsContext gc=c.getGraphicsContext2D();

		//StrinG.setToggleGroup(tg);
		//Integerr.setToggleGroup(tg);
		//Integerr.setSelected(true);
		Button Bf=new Button ("Confirm Choice");
		Bf.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				int n=Integer.parseInt(t1.getText());
				if(StrinG.isSelected())
				 {
				 	int t=1;
				 	String str;
				 	Gen<String> g1=new Gen<String>(n);
				 	gc.fillText("Generic String Class Of "+n+" elements allocated",60,60);
				 	while(t==1){
				 	System.out.println("1.Push or 2.Pop");
				 	int h=sc.nextInt();
				 	if(h==1){
				 	System.out.println("1.Enter element to be inserted");
				 	String p=sc.nextLine();
					g1.insertt(p);
				 	}
				 	else
				 	{
				 		str=g1.delete();
				 	}
				 	t=sc.nextInt();
				 	}
				 	gc.clearRect(0,0,400,400);
				 	
				 }
				else
				{
					int t=1;
					int f;
					gc.clearRect(0,0,400,400);
					Gen<Integer> g1=new Gen<Integer>(n);
					while(t==1){
				 	System.out.println("1.Push or 2.Pop");
				 	int h=sc.nextInt();
				 	if(h==1){
				 	System.out.println("1.Enter element to be inserted");
				 	int p=sc.nextInt();
					g1.insertt(p);
				 	}
				 	else
				 	{
				 		f=g1.delete();
				 	}
				 	t=sc.nextInt();
				 	}
					gc.fillText("Generic Integer Class Of "+n+" elements allocated",60,60);
				}
			}

		});
		GridPane rootnode=new GridPane();
		 rootnode.add(response,0,1);
		 rootnode.add(StrinG,0,2);
		 rootnode.add(Integerr,1,2);
		 rootnode.add(Bf,0,4);
		 rootnode.add(r2,0,3);
		 rootnode.add(t1,1,3);
		 rootnode.add(c,0,0);
		//FlowPane root=new FlowPane();
		//root.getChildren().addAll(Bf,response,sp,StrinG,Integerr,r2,t1);
		Scene myScene=new Scene(rootnode,550,500);
		myStage.setScene(myScene);
		myStage.show();

	}
public static void main(String args[])
	{
		launch(args);
	}
}
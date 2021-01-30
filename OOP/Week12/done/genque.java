import javafx.application.*;
import javafx.scene.*;
import javafx.scene.canvas.*; 
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.geometry.*;
import javafx.event.*;
class Gen<T>
{
	int n;
	T arr[];
	int f;
	int r;
	Gen(int n)
	{
		f=-1;
		r=-1;
		this.n=n;
		arr=(T[])new Object[n];
	}
	public void insertt(T data)
	{
			if(f==-1)
			{
				f=0;
			}
			arr[++r]=data;
		
	}
	public void display()
	{
		for(int i=0;i<r;i++)
		{
			System.out.println(arr[i]+" ");

		}
	}
}
public class genque extends Application
{
	public void start(Stage myStage)
	{
		Gen<String> stn=new Gen<String>(5);
		Gen<Integer> inn=new Gen<Integer>(5);
		FlowPane root=new FlowPane();
		Label response=new Label("Start which type of Generic class");
		TextField tf1=new TextField();
		Label n=new Label("Enter element to be inserted");
		TextField tf2=new TextField();
		tf2.setPromptText("0");
		Button Inse=new Button("Insert");	
		Button Display=new Button("Display");
		Inse.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae){
			if(tf1.getText().equals("String"))
			{
				String s=tf2.getText();
				stn.insertt(s);
			}
			else
			{
				int num=Integer.parseInt(tf2.getText());
				inn.insertt(num);
			}
		}
		});
		Display.setOnAction(new EventHandler<ActionEvent>(){
	public void handle(ActionEvent ae)
	{	
			if(tf1.getText().equals("String"))
			{
				stn.display();
			}
			else
			{
				inn.display();
			}

	}
		});
	
		root.getChildren().addAll(response,tf1,n,tf2,Inse,Display);
		Scene myScene=new Scene(root,400,400);
		myStage.setScene(myScene);
		myStage.show();


		}
public static void main(String args[])
	{
		launch(args);
	}
}
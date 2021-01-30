import javafx.application.*;
 import javafx.scene.*;
 import javafx.scene.control.*;
 import javafx.scene.layout.*;
 import javafx.stage.*;
 import javafx.geometry.*;
 import javafx.event.*;
interface GenInt<T>{
	void insert(T data);
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
	}
	public void insert(T data)
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
public class mindb2 extends Application
{
	Label response;
	public void start(Stage myStage)
	{
		Label response=new Label("Select which type of Generic Class is to be made");
		//Separator sp=new Separator();
		//sp.setPrefWidth(180);
		//ToggleGroup tg=new ToggleGroup();
		CheckBox StrinG=new CheckBox("String Queue");
		CheckBox Integerr=new CheckBox("Integer Queue");
		Label r2=new Label("Enter max size of Generic Queue");
		TextField t1=new TextField();

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
				 	//Gen<String> g1=new Gen<String>(n);
				 	response.setText("Generic String Class Of "+n+" elements allocated");
				 }
				else
				{
					//Gen<Integer> g1=new Gen<Integer>(n);
					response.setText("Generic String Class Of "+n+" elements allocated");
				}
			}

		});
		// GridPane rootnode=new GridPane();
		// rootnode.add(response,0,0);
		// rootnode.add(StrinG,0,1);
		// rootnode.add(Integerr,1,1);
		// rootnode.add(Bf,0,3);
		// rootnode.add(r2,0,2);
		// rootnode.add(t1,1,2);
		FlowPane root=new FlowPane();
		root.getChildren().addAll(Bf,response,StrinG,Integerr,r2,t1);
		Scene myScene=new Scene(root,200,200);
		myStage.setScene(myScene);
		myStage.show();

	}
public static void main(String args[])
	{
		launch(args);
	}
}
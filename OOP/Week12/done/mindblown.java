import java.util.Scanner.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.geometry.*;
import javafx.event.*;
class QueFullException extends Exception{
	QueFullException(String message)
	{
		super(message);
	}
}
class QueEmptyException extends Exception{
	QueEmptyException(String message)
	{
		super(message);
	}
}
class Gen<T>
{
	int n;
	T arr[];
	int f=-1;
	int r=-1;
	Gen(int n)
	{
		this.n=n;
	}
		public void insert(T data)throws QueFullException{	
		try{
		if(r==n-1)
			throw new QueFullException("Queue is full");
		else{
			if(f==-1)
			{
				f=0;
			}
			arr[++r]=data;
		}
	}
	catch(QueFullException yo)
	{
		System.out.println("oop");
	}
}
	public T delete()throws QueEmptyException{
		try{
		if(f==-1){
			throw new QueEmptyException("Queue is Empty");
	}
		else{
			T ret;
			ret=arr[f++];
			return ret;
			}
	}
	catch(QueEmptyException yo){
		System.out.println("oop");
	}
	return null;
}
}
public class mindblown extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		Label response=new Label("Select which type of Generic Class is to be made");
		//Separator sp=new Separator();
		//sp.setPrefWidth(180);
		ToggleGroup tg=new ToggleGroup();
		RadioButton StrinG=new RadioButton("String Generic Queue");
		RadioButton Integerr=new RadioButton("Integer Generic Queue");
		Label r2=new Label("Enter max size of Generic Queue");
		TextField t1=new TextField();

		StrinG.setToggleGroup(tg);
		Integerr.setToggleGroup(tg);
		Integerr.setSelected(true);
		Button B=new Button ("Confirm Choice");
		B.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				int n=Integer.parseInt(t1.getText());
				if(StrinG.isSelected())
				{
					Gen<String> g1=new Gen<String>(n);
					response.setText("Generic String Class Of "+ n+" elements allocated");
				}
				if(Integerr.isSelected())
				{
					Gen<Integer> g1=new Gen<Integer>(n);
					response.setText("Generic Integer Class Of "+ n+" elements allocated");
					try{
					g1.insert(2);
				}
				catch(QueFullException e)
				{
					System.out.println(e);
				}
			}
		}

		});
		GridPane rootnode=new GridPane();
		Scene myScene=new Scene(rootnode,200,200);
		rootnode.add(response,0,0);
		rootnode.add(StrinG,0,1);
		rootnode.add(Integerr,1,1);
		rootnode.add(B,0,3);
		rootnode.add(r2,0,2);
		rootnode.add(t1,1,2);
		myStage.setScene(myScene);
		myStage.show();

	}

}

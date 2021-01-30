import java.util.Scanner.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.geometry.*;
import javafx.event.*;
public class string extends Application
{
	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage myStage)
	{
		String str;
		FlowPane root=new FlowPane(10,10);

		Label l1=new Label("Enter two Strings");
		TextField t1=new TextField();
		TextField t2=new TextField();
		t1.setPromptText("String 1");
		t2.setPromptText("String 2");
		RadioButton one=new RadioButton("2 Sub of 1?");
		RadioButton three=new RadioButton("StartsWith or EndsWidth");
		RadioButton two=new RadioButton("Both initials ka new String");
		RadioButton four=new RadioButton("Equals");
		RadioButton five=new RadioButton("Compare");
		ToggleGroup tg=new ToggleGroup();
		one.setToggleGroup(tg);
		two.setToggleGroup(tg);
		three.setToggleGroup(tg);	
		four.setToggleGroup(tg);
		five.setToggleGroup(tg);	
		

		//one.setSelected(true);
		one.fire();
		Button B=new Button ("Confirm Choice");
		B.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				if(one.isSelected())
				{
					int n=(t2.getText()).indexOf(t1.getText());
					if(n!=-1){
						System.out.println("Yes String 1 is a Substring of String 2");
					}
					else{
						System.out.println("NO");
					}
				}
				else if(two.isSelected()){
					String p=Character.toString((t1.getText()).charAt(0))+Character.toString((t2.getText()).charAt(0));
					System.out.println(p);
				}
				else if(three.isSelected()){
					if((t2.getText()).startsWith(t1.getText()))
					{
						System.out.println("Yes it startsWith");
					}
					if((t1.getText()).endsWith(t2.getText()))
						System.out.println("Yes it end with");
				}
				else if(four.isSelected()){
					String s[]=t1.getText().split("\\s+");
					System.out.println(s[2]);
				}
				else{
					int p=(t1.getText()).compareTo(t2.getText());
					System.out.println(p);
				}
		
		}

		});

		root.getChildren().addAll(l1,t1,t2,one,two,three,four,five,B);
		Scene myScene=new Scene(root,400,400);
		myStage.setScene(myScene);
		myStage.show();
	}

}

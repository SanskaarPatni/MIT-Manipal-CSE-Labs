import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.geometry.*;
import javafx.event.*;
public class fourth extends Application{
	Label response;
	public void start(Stage primaryStage){
		GridPane root=new GridPane();
		root.setHgap(10);
		root.setVgap(10);
		Label lb1=new Label();
		Label l1=new Label();
		l1.setText("First Number");
		Label pw1=new Label();
		Label response=new Label();
		lb1.setText("Welcome");
		pw1.setText("Second Number");
		TextField tf1=new TextField();
		TextField p1=new TextField();
		Button sigi=new Button("Sign In");
		sigi.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				response.setText("Gcd of the two numbers "+ gcd(Integer.parseInt(tf1.getText()),Integer.parseInt(p1.getText())));
			}
		});

		primaryStage.setTitle("GCD of two numbers");
		root.add(lb1,0,0);
		root.add(l1,0,1);
		root.add(tf1,0,2);
		root.add(pw1,0,3);
		root.add(p1,0,4);
		root.add(sigi,0,5);
		root.add(response,1,5);
		root.setAlignment(Pos.CENTER);
		Scene myScene=new Scene(root,500,200);
		primaryStage.setScene(myScene);
		primaryStage.show();
	} 
	public static void main(String args[]){
		launch(args);
	}
	public int gcd(int a,int b){
        if (b!= 0)
            return gcd(b, a % b);
        else
            return a;
    }	
	}

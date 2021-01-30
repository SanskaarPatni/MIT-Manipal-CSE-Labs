import javafx.scene.control.*;
import javafx.scene.control.TextField;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.geometry.*;
import javafx.event.*;
public class third1 extends Application{
	Label response;
	public void start(Stage primaryStage){
		GridPane root=new GridPane();
		root.setHgap(10);
		root.setVgap(10);
		Label lb1=new Label();
		Label l1=new Label();
		l1.setText("Username:");
		Label pw1=new Label();
		Label response=new Label();
		lb1.setText("Welcome");
		pw1.setText("Password");
		lb1.setTextFill(Color.MAGENTA);
		TextField tf1=new TextField();
		PasswordField p1=new PasswordField();
		Button sigi=new Button("Sign In");
		sigi.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				response.setText("Welcome "+ tf1.getText());
			}
		});
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
}
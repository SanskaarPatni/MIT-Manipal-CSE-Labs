import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
public class first extends Application{
	public void start(Stage primaryStage){
		Label lb1=new Label();
		lb1.setText("Welcome to JavaFX programming");
		lb1.setTextFill(Color.MAGENTA);
		primaryStage.setTitle("This is the first JavaFX Application");
		FlowPane root=new FlowPane();
		root.getChildren().add(lb1);
		root.setVgap(4);
		root.setHgap(4);
		Scene myScene=new Scene(root,500,200);
		primaryStage.setScene(myScene);
		primaryStage.show();
	}
	public static void main(String args[]){
		launch(args);
	}
}
import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
public class solve1 extends Application{
	public void start(Stage primaryStage){
		Label lb1=new Label();
		lb1.setText("Hello World from JavaFX");
		lb1.setTextFill(Color.RED);

		FlowPane root=new FlowPane();
		root.getChildren().add(lb1);
		Scene myScene=new Scene(root,500,200);
		primaryStage.setScene(myScene);
		primaryStage.show();
	}
	public static void main(String args[]){
		launch(args);
	}
}
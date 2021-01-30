import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.event.*;
import javafx.geometry.*;

public class tf extends Application
{
	TextField tf;
	Label response;

	public static void main(String args[])
	{
		launch(args);
	}
	public void start(Stage ps)
	{
		ps.setTitle("TextField");
		FlowPane root=new FlowPane(10,10);
		root.setAlignment(Pos.CENTER);
		Scene myScene=new Scene(root,500,500);
		ps.setScene(myScene);
		response=new Label("Search String");


		Button b=new Button("Get Search String");

		tf=new TextField();
		tf.setPromptText("Enter Search String");
		//tf.setPrefColumnCount(15);

		tf.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				response.setText("Search string: "+tf.getText());
			}
		});
		b.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae)
			{
				response.setText(tf.getText());
			}
		});
		Separator sep=new Separator();
		sep.setPrefWidth(400);
		root.getChildren().addAll(response,tf,b,sep);
		ps.show();
	}

}
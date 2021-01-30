import javafx.scene.control.*;
import javafx.scene.control.TextField;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.geometry.*;
import javafx.event.*;
public class third extends Application{
	Label response;
	public void start(Stage primaryStage){
		FlowPane root=new FlowPane();
		root.setHgap(10);
		root.setVgap(10);
		Label lb1=new Label();
		Label response=new Label();
		lb1.setText("Welcome");
		
		lb1.setTextFill(Color.MAGENTA);
		TextField tf1=new TextField();
		PasswordField p1=new PasswordField();
		Button sigi=new Button("Sign In");
		sigi.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent ae){
				response.setText("Welcome "+ tf1.getText());
			}
		});

		primaryStage.setTitle("This is the first JavaFX Application");
		
		root.getChildren().addAll(lb1,tf1,sigi,response,p1);
		root.setAlignment(Pos.CENTER);
		Scene myScene=new Scene(root,500,200);
		primaryStage.setScene(myScene);
		primaryStage.show();
	}     
      //creating label email 
     /* GridPane gridPane = new GridPane();  
      Text text1 = new Text("Email");       
      
      //creating label password 
      Text text2 = new Text("Password"); 
	  
      //Creating Text Filed for email        
      TextField textField1 = new TextField();       
      
      //Creating Text Filed for password        
      TextField textField2 = new TextField();  
       
      //Creating Buttons 
      Button button1 = new Button("Submit"); 
      Button button2 = new Button("Clear");  
      
      //Creating a Grid Pane 
        
      
      //Setting size for the pane  
      gridPane.setMinSize(400, 200); 
       
      //Setting the padding  
      gridPane.setPadding(new Insets(10, 10, 10, 10)); 
      
      //Setting the vertical and horizontal gaps between the columns 
      gridPane.setVgap(5); 
      gridPane.setHgap(5);       
      
      //Setting the Grid alignment 
      gridPane.setAlignment(Pos.CENTER); 
       
      //Arranging all the nodes in the grid 
      gridPane.add(text1, 0, 0); 
      gridPane.add(textField1, 1, 0); 
      gridPane.add(text2, 0, 1);       
      gridPane.add(textField2, 1, 1); 
      gridPane.add(button1, 0, 2); 
      gridPane.add(button2, 1, 2);  
      
      //Creating a scene object 
      Scene scene = new Scene(gridPane);  
      
      //Setting title to the Stage 
      stage.setTitle("Grid Pane Example"); 
         
      //Adding scene to the stage 
      stage.setScene(scene); 
         
      //Displaying the contents of the stage 
      stage.show(); 

	}*/
	public static void main(String args[]){
		launch(args);
	}
}
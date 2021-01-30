import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.geometry.*;
import javafx.event.*;
import javafx.scene.canvas.*;
public class prob1 extends Application
{
    public void start(Stage ps)
    {
        ps.setTitle("JAVAFX CALCULATOR");
        Label num1=new Label();
        num1.setText("NUMBER 1:");
        TextField num1t=new TextField();
        Label num2=new Label();
        num2.setText("NUMBER 2:");
        TextField num2t=new TextField();
        Button compute=new Button("COMPUTE"); 
        Canvas c=new Canvas(400,400);
        GraphicsContext gc=c.getGraphicsContext2D();
        gc.setLineWidth(1.0);
        compute.setOnAction(new EventHandler<ActionEvent>()
        {
            public void handle(ActionEvent ae)
            {
                double n1=Double.parseDouble(num1t.getText());
                double n2=Double.parseDouble(num2t.getText());
                gc.clearRect(0,0,400,400);
                String st="********EVALUATING***********\n"+
                "SUM= " +(n1+n2)+"\n"+
                "PRODUCT= " +(n1*n2)+"\n"+
                "DIFFERENCE= " +(n1-n2)+"\n"+
                "QUOTIENT= " +(n1/n2)+"\n";
                gc.fillText(st,60,40);
            }
        });
        FlowPane root=new FlowPane();
	root.getChildren().addAll(num1,num1t,num2,num2t,compute,c);
	Scene myScene=new Scene(root,700,300);
	ps.setScene(myScene);
	ps.show();
    }
    public static void main(String []args)
    {
        launch(args);
    }
}
import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.Scene;
import javafx.event.*;
import javafx.scene.canvas.*;
import javafx.geometry.*;
import javafx.scene.paint.*;
public class second extends Application
{
	public void start(Stage ps)
	{
		Label lb1=new Label();
		lb1.setText("Welcome!");
		Label us=new Label();
		us.setText("NUMBER: ");
		TextField ust=new TextField();
		Button bt=new Button("Generate Table!");
		Canvas c=new Canvas(400,400);
		GraphicsContext ctx=c.getGraphicsContext2D();
		//ctx.setLineWidth(1.0);
		bt.setOnAction(new EventHandler<ActionEvent>(){
		public void handle(ActionEvent ae){
		int n1=Integer.parseInt(ust.getText());
		int i=0;
		String s="";
		for(i=1;i<11;i++)
		{
			s=s+(i+"*"+n1+"= "+(i*n1)+"\n");
		}
		ctx.fillText(s,0,10);
		}});
		FlowPane root=new FlowPane();
		//root.setAlignment(Pos.CENTER);
		root.getChildren().addAll(lb1,us,ust,bt,c);
		Scene myScene=new Scene(root,700,300);
		ps.setScene(myScene);
		ps.show();
		
	}
	public static void main(String []args)
	{
		launch(args);
	}
}
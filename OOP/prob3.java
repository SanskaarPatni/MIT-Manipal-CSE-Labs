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
class NewThread implements Runnable
{
    GraphicsContext gc;
    String st;
    Thread t;
    int v;
    NewThread(GraphicsContext ob,String s,int m)
    {
        t=new Thread(this);
        gc=ob;
        v=m;
        st=s;
        t.start();
    }
    public void run()
    {
        if(v==0)
        {
            for(;;)
            {
                //gc.clearRect(0,0,400,400);
                gc.fillText(st,60,40);
                st=st.substring(1)+st.charAt(0);
                try{
                Thread.sleep(1000);
            }catch(InterruptedException e){System.out.println(e);}
            }
        }
        else
        {
            for(;;)
            {
                //gc.clearRect(0,0,400,400);
                gc.fillText(st,60,40);
                st=st.charAt(st.length()-1)+st.substring(0,st.length()-1);
                try{
                Thread.sleep(1000);
                }
            catch(InterruptedException e){System.out.println(e);}
            }
        }
    }
}
public class prob3 extends Application
{
    public void start(Stage ps)
    {
        ps.setTitle("LEFT-RIGHT-LEFT");
        Label lb=new Label("INPUT TEXT: ");
        TextField tf=new TextField();
        CheckBox left=new CheckBox("LEFT");
        CheckBox right=new CheckBox("RIGHT");
        Button m=new Button("DISPLAY");
        Canvas c=new Canvas(400,400);
        GraphicsContext gc=c.getGraphicsContext2D();
        gc.setLineWidth(1.0);
        m.setOnAction(new EventHandler<ActionEvent>()
        {
            public void handle(ActionEvent ae)
            {
                if(left.isSelected())
                {
                    new NewThread(gc,tf.getText(),0);
                }
                else
                {
                    new NewThread(gc,tf.getText(),1);
                }
            }
        });
        FlowPane root=new FlowPane();
	root.getChildren().addAll(lb,tf,left,right,m,c);
	Scene myScene=new Scene(root,700,300);
	ps.setScene(myScene);
	ps.show();
    }
}
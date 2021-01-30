import java.util.*;
abstract class Figure{
	float d1,d2;
	Figure(float i,float j){
		d1=i;
		d2=j;
	}
	abstract void area();
}
class Rectangle extends Figure{
	Rectangle(float x,float y){
		super(x,y);
	}
	void area(){
		System.out.println("Area of Rectangle is "+d1*d2);
	}
}
class Triangle extends Figure{
	Triangle(float x,float y){
		super(x,y);
	}
	void area(){
		System.out.println("Area of Triangle is "+ (0.5*d1*d2));
	}
}
class Square extends Figure{
	Square(float x,float y){
		super(x,y);
	}
	void area(){
		System.out.println("Area of Square using only d1 is "+ d1*d1);
	}
}

class testFigure{
	public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
    System.out.println("Enter dimensions d1 and d2");
    float c=sc.nextFloat();
    float d=sc.nextFloat();
    Figure f;
	Rectangle R=new Rectangle(c,d);
	f=R;
	R.area();
	Square S=new Square(c,d);
	f=S;
	S.area();
	Triangle T=new Triangle(c,d);
	f=T;
	T.area();
}
}

class Numeric<T extends Number>
{
	T num;
	Numeric(T n){
		num=n;
	}
	boolean absequal(Numeric<?>ob){
		if(Math.abs(num.doubleValue())==Math.abs(ob.num.doubleValue()))
			return true;
		return false;
	}
}
class fourth{
	public static void main(String args[]){
		//Numeric<String>iob=new Numeric<String>("");
		Numeric<Integer>iob=new Numeric<Integer>(6);
		Numeric<Double>doi=new Numeric<Double>(6.0);
		if(iob.absequal(doi))
		{
			System.out.println("Equal");
		}
		else{
			System.out.println("UnEqual");

		}
	}
}
class test1{
	 void pest(){
		System.out.println("a");
	}
	
void pest(double x){
		 System.out.println("F");
	}

}
class testt extends test1{
	void pest(){
		System.out.println("b");
	}
//yehi cheez agar double laau ismein and t.pest(1) hi karunga kyuki doubke cant be converted into int but int can to double 
void pest(int x){
		 System.out.println("b");
	}

}
class test{
	public static void main(String args[]){
    testt t=new testt();
    int tf=1;
    t.pest(tf);
	}
}

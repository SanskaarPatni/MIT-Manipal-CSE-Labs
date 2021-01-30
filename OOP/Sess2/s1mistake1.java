public class s1mistake1{
	static int bump(int i){
		return i+2;
	}
	public static void main (String args[]){
		//x should be equal to bump(x)
		for(int x=0;x<5;x=bump(x)){
			System.out.println(x +" ");
		}
	}
}

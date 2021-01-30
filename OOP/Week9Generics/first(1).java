import java.util.Scanner;
class GArray{

	public static <T> void exchange (T [] arr, int a, int b) {
		T temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	
	public static <T> void display (T [] arr) {
		for (T obj: arr)
			System.out.print("\t" + obj);
		System.out.println();
	}
	
}

public class first{
	public static void main (String [] args) {
		Scanner sc=new Scanner(System.in);
		Integer intArray[] = {1,2,3,4,5};
		Double doubleArray[] = {11.11, 33.3, 22.22};
		String stringArray[] = {"A", "B", "C", "D"};
		
		System.out.println("Initally: ");
		GArray.display(intArray);
		GArray.display(doubleArray);
		GArray.display(stringArray);
		System.out.println("Enter positions whose elements are to be swapped");
		int a=sc.nextInt();
		int b=sc.nextInt();
		System.out.println("\n\tSwapping positions "+ a+" and "+b);
		GArray.exchange(intArray, a-1, b-1);
		GArray.exchange(doubleArray, a-1, b-1);
		GArray.exchange(stringArray, a-1, b-1);
		
		GArray.display(intArray);
		GArray.display(doubleArray);
		GArray.display(stringArray);
	
	}

}
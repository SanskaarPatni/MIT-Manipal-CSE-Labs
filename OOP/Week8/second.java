import java.util.Scanner;
class RowSum implements Runnable{
	private int a[];
	int sum;
	RowSum(int a[]){
		this.a=a;
		sum=0;
	}
	public int getRowSum()
	{
		System.out.println("Row Sum is "+sum);
		return sum;
	}
	public void run(){
		for(int i:a){
			sum=sum+i;
		}
	}
}

class Matrix {
	private int arr[][];
	
	public Matrix (int n, int m) {
		arr = new int[n][n];
	}

	public int[] getRow (int i) {
		return arr[i];
	}

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.println("\nEnter the matrix: ");
		for (int i = 0; i < arr.length; ++i)
			for (int j = 0; j < arr[i].length; ++j)
				arr[i][j] = sc.nextInt();
	}

}
public class second{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter dimenesions of Matrix:");
		int n=sc.nextInt();
		int m=sc.nextInt();
		Matrix matrix=new Matrix(n,m);
		matrix.input();
		Thread t[]=new Thread[n];
		RowSum rowsum[]=new RowSum[n];
		for(int i=0;i<n;i++){
			rowsum[i]=new RowSum(matrix.getRow(i));
			t[i]=new Thread(rowsum[i]);
			t[i].start();
		}
		int sum=0;
		try{
			for(int i=0;i<n;i++)
			{
				t[i].join();
				sum=sum+rowsum[i].getRowSum();
			}
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println("Total sum "+sum);
	}
}

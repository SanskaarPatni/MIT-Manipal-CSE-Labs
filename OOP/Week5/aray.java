import java.util.Arrays;
import java.util.Scanner;
class aray{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]={3,2,1};
		int b[]=new int[3];
		for(int i=0;i<3;i++)
		{
			b[i]=sc.nextInt();
		}
		boolean f=Arrays.equals(a,b);
		Arrays.sort(a);
		System.out.println(f);
		System.out.println(a.toString());
	}
}
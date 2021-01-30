import java.util.Scanner;
class EArray<T>
{
	T arr[];
	void exchange(int a,int b){
		T temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
}
class exchange{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter length of array:");
		int n=sc.nextInt();
		System.out.println("Enter type of array:");
		System.out.println("1.Integer\n2.String");
		int t=sc.nextInt();
		if(t==1){
			EArray<Integer> e=new EArray<Integer>();
			int i=0;
			System.out.println("Enter n elements of array:");
			for(i=0;i<n;i++){
				e.arr[i]=sc.nextInt();
			}
			System.out.println("Enter 2 positions to swap:");
			int a=sc.nextInt();
			int b=sc.nextInt();
			e.exchange(a,b);
		}
	}
}
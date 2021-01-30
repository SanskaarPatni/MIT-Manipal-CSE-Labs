import myPackages.p1.Maximum;
import java.util.*;
class testPackageMaximum{
	public static void main(String args[]){
		Maximum my=new Maximum();
		Scanner sc=new Scanner(System.in);
		System.out.println("1.Max 3 ints\n2.Max 3 floats.\n3.Max in array\n4.Max in a matrix");
		System.out.println("Your choice:");
		int t=sc.nextInt();
		switch(t){
			case 1:
			System.out.println("Enter three integers:");
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=sc.nextInt();
			int large=my.max(a,b,c);
			System.out.println("Largest is: "+large);
			break;
			case 2:
			System.out.println("Enter three floating point numbers:");
			float d=sc.nextFloat();
			float e=sc.nextFloat();
			float f=sc.nextFloat();
			float largee=my.max(d,e,f);
			System.out.println("Largest is: "+largee);
			break;
			case 3:
			System.out.println("Enter number of integers in an array:");
			int n=sc.nextInt();
			int k[]=new int[n];
			for(int i=0;i<n;i++){
				System.out.println("Enter element:");
				k[i]=sc.nextInt();
			}
			int largeee=my.max(k);
			System.out.println("Largest is: "+largeee);
			break;
			case 4:
		    System.out.println("Enter size of the matrix: ");
					int r = sc.nextInt();
					int m = sc.nextInt();
					int mat[][] = new int[r][m];
					System.out.println("Enter the matrix: ");
					for(int i = 0; i < r; ++i)
						for (int j = 0; j < m; ++j)
							mat[i][j] = sc.nextInt();
					System.out.println("Largest = " + my.max(mat));
	
			break;

		}
	}

		
	}

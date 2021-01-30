class fibarray
{
	public static int[] yo()
	{
		int arr[]=new int[10];
		int i=2;
		arr[0]=0;
		arr[1]=1;
		while(i<10)
		{
			arr[i]=arr[i-1]+arr[i-2];
			i++;
		}

		for(int j=0;j<arr.length;j++)
		{
			System.out.println(arr[j]+" ");
		}
		return arr;
	}
	public static void main(String[] args) {
	
	int arr[]=yo();
for(int j=0;j<arr.length;j++)
		{
			System.out.println(arr[j]+" ");
		}
}
}
class LengthDemo{
	public static void main(String[] args) {
		// done:
		// for(int i=0;i<10;i++)
		// {
		// 	for(int j=0;j<10;j++)
		// {
		// 	for(int k=0;k<10;k++)
		// {
		// 	System.out.println(k);
		// 	if(k==5)
		// 	{
		// 		break done;
		// 	}
		// }
		// System.out.println("After k loop");

			
		// }

		// }
		int nums[]={1,2,3};
		/*for(int x: nums)
		{
			System.out.println(x);
			x=x*10;
		}
		for(int x: nums)
		{
			System.out.println(x);
		}*/
		for(int i=0;i<3;i++)
		{
			System.out.println(nums[i]);
			nums[i]=nums[i]*2;
			System.out.println(nums[i]);
		}
		
	}
}
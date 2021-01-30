class catchor{
	public static void main(String args[]){
		int a=88,b=0;
		int result;
		char chrs[]={'a','b','c'};

		for(int i=0;i<2;i++){
			try{
				if(i==0){
					result=a/b;

				}
				else{
					chrs[5]='X';
				}
			}
			catch(ArithmeticException | ArrayIndexOutOfBoundsException e){
				System.out.println("Exception caught: "+ e);
			}
		}
		System.out.println("After multi-catch.");
	}
}
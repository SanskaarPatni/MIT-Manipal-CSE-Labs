import java.util.Scanner;
class MainStack{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int y=sc.nextInt();
		Stack myStack1=new Stack(y);
		int n;
		for(int i=0;i<myStack1.stack.length;i++){
			n=sc.nextInt();
			myStack1.push(n);
		}

		myStack1.display();
		System.out.println("Popped elements are:");
		for(int i=0;i<y;i++){
			System.out.print(myStack1.pop()+" ");
		}
	}
}
class Stack{
	  int stack[];
	  int tos;
       Stack(int x){
       	tos=-1;
    	stack=new int[x];
    }
    void push(int item){
		if(tos==stack.length-1){
			System.out.println("Stack OverFlow");
		}
		else stack[++tos]=item;
	}
    void display(){
        System.out.println("Stack contains:");
        for(int i=0;i<=tos;i++){
        	System.out.print(stack[i] + " ");

        }
    }
    int pop(){
    	if(tos<0){
    		System.out.println("Stack UnderFlow");
    		return -13213;
    	}

    return	stack[tos--];
     }

}
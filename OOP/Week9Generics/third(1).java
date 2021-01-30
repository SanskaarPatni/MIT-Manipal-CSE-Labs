import java.util.Scanner;
class Node<T>
{
	T data;
	Node <T> next;
	Node(T data){
		this.data=data;
	}
	void displayNode(){
		System.out.println(data+" ");
	}
}
class LinkedList<T>
{
	Node<T> first;
	LinkedList(){
		first=null;
	}
	void insertFront(T data)
	{
		Node<T> temp=new Node<T>(data);
		if (first== null)
			first= temp;
		else {
			temp.next =first;
			first= temp;
		}
	}
	Node<T> deleteFront(){
		if(first==null){
			System.out.println("List is empty");
			return null;
		}
		else
		{
			Node<T>temp=first;
			first=first.next;
			return temp;
		}
	}
	void Display(){
		Node<T>temp=first;
		while(temp!=null){
			temp.displayNode();
			temp=temp.next;
		}
	}
}
class third{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int lch = 0;
		System.out.printf("\n1. Integer List\n2. Double List\nChoice: ");
		lch=sc.nextInt();
		LinkedList<Integer> integerList = new LinkedList<Integer>();
		LinkedList<Double> doubleList = new LinkedList<Double>();
		int ch;
			do {
				System.out.print("\n1. Insert Front\n2. Delete Front\n3. Display\nChoice: ");
				ch = sc.nextInt();

				if (ch == 1) {
					System.out.printf("Enter item to be inserted: ");
					if (lch == 1)
						integerList.insertFront(sc.nextInt());
					else if (lch == 2)
						doubleList.insertFront(sc.nextDouble());
				}
				else if (ch == 2) {
					if (lch == 1){
						Node<Integer>item;
						item = integerList.deleteFront();
						item.displayNode();
					}
					else if (lch == 2)
					{
						Node<Double>item;
						item = doubleList.deleteFront();
						item.displayNode();
					}
						
				}
				else{
				if (lch == 1){
					System.out.println("Integer list:\n");
					integerList.Display();
					}
				else if (lch == 2)
				{
					System.out.println("Double list:\n");
					doubleList.Display();
				}
			} 
		}while (ch >= 1 && ch<=3);
		
}
}
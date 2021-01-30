import java.util.Scanner;

class Stack<T> {
	T arr[];
	int tos;

	public Stack (int n) {
		tos = -1;
		arr = (T []) new Object[n];
	}
	
	public boolean isEmpty () {
		return (tos == -1);
	}

	public void push (T item) {
		if (tos == arr.length - 1) {
			System.out.println("STACK OVERFLOW!");
			return;
		}
		arr[++tos] = item;
	}

	public T pop () {
		if (tos == -1) {
			System.out.println("STACK UNDERFLOW!");
			return null;
		}
		return arr[tos--];
	}
	public void Display(){
		for(int i=0;i<=tos;i++){
			System.out.println(arr[i]);
		}
		}
}

class Student {
	String name;
	double cgpa;

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter student name: ");
		name = sc.nextLine();
		System.out.print("Enter student cgpa: ");
		cgpa = sc.nextDouble();
	}
	public String toString () {
		return "STUDENT NAME: " + name + "\nSTUDENT CGPA: " + cgpa + "\n"; 
	}
}

class Employee {
	String name; 
	String idno;

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter employee name: ");
		name = sc.nextLine();
		System.out.print("Enter employee id: ");
		idno = sc.nextLine();
	}
	public String toString () {
	return "EMPLOYEE NAME: " + name + "\nEMPLOYEE ID: " + idno + "\n"; 
	}

}

public class second{

	public static void main (String [] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the size of the stacks: ");
		int n = sc.nextInt();
		Stack <Student> sstack = new Stack<Student>(n);
		Stack <Employee> estack = new Stack<Employee>(n);
		int choice;
		System.out.println("1. Student\n2. Employee\nENTER YOUR CHOICE: ");
			choice = sc.nextInt();
			if (choice < 1 || choice > 2) {
				System.out.println("Invalid Choice!");
				System.exit(0);
			}
			int stch;
			do {
				System.out.print("1. Push\n2. Pop\n3. Display\nChoice: ");
				stch = sc.nextInt();
				
				if (stch < 1 || stch > 3)
					break;
					
				if (stch == 1) {
					if (choice == 1) {
						Student stud = new Student();
						stud.input();
						sstack.push(stud);
					}
					else {
						Employee empl = new Employee();
						empl.input();
						estack.push(empl);
					}
				}
				else if (stch == 2) {
					if (choice == 1) {
						Student stud = sstack.pop();
						if (stud != null)
							System.out.print("\nPopped: " + stud);
					}
					else {
						Employee empl = estack.pop();
						if (empl != null)
							System.out.print("\nPopped: " + empl);
					}
				}
				else{
					if (choice == 1) {
						sstack.Display();
					}
					else {
						estack.Display();
					}
				}
			} while (stch >= 1 && stch <= 3);
}
}

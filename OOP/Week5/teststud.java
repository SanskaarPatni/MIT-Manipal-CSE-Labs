import java.util.*;
class Student{
	int reg_no;
	String Name;
	GregorianCalendar date;
	short sem;
	float gpa;
	float cgpa;
	static int count=0;
    Student(String name,GregorianCalendar Date,short Sem,float Gpa,float Cgpa){
    	count++;
    	Name=name;
    	date=Date;
    	reg_no=(((Date.get(Calendar.YEAR))%100)*100)+count;
    	sem=Sem;
    	gpa=Gpa;
    	cgpa=Cgpa;
}

Student(){
	count++;
	reg_no=1208;
	Name ="Sanskaar";
	date=new GregorianCalendar(2019,8,19);
	sem=3;
	gpa=9.3f;
	cgpa=9.27f;
}

void Display(){
	System.out.println("Student details are:");
	System.out.println("Name: "+Name);
    System.out.println("Registration number: "+reg_no);
	Formatter first=new Formatter();
	first.format("%tD",date);
	System.out.println("Date of joining is: "+first);
	System.out.println("CGPA" + cgpa);
	System.out.println("GPA" + gpa);
	System.out.println("Sem" + sem);
}

void sortsem(Student a[],int n){
	Student temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].sem>a[j+1].sem){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].sem==a[j+1].sem && a[j].cgpa>a[j+1].cgpa)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}

	}
	System.out.println("Record arranged in Ascending Order with respect to Semester and then CGPA too");
	for(int i=0;i<n;i++){
		a[i].Display();
		
	}
}

void sortname(Student a[],int n){
	Student temp;
		for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j].Name.compareTo(a[j+1].Name)>0){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}
for(int i=0;i<n;i++){
	a[i].Display();
}
}
void partChar(Student a[],int n,char s){
	for(int i=0;i<n;i++){
		if(a[i].Name.charAt(0)==s){
			System.out.println(a[i].Name);
		}
	}
}
void partSubString(Student a[],int n,String s){
	for(int i=0;i<n;i++){
		if(a[i].Name.indexOf(s)>0){
			System.out.println(a[i].Name);
		}
	}
}
void initials(Student a[],int n){
	for(int i=0;i<n;i++){
			String [] words=a[i].Name.split("\\s+");
			String newd="";
			newd=Character.toString(words[0].charAt(0));
			newd=newd +"."+Character.toString(words[1].charAt(0));
			a[i].Name=newd +" "+ words[2];
		}
	

for(int i=0;i<n;i++){
	a[i].Display();
}
}



class teststud{
	public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Default Student:");
        Student s1=new Student();
		s1.Display();
		System.out.println("Enter number of Students:");
		int n=sc.nextInt();
        Student s[]=new Student[n];
		for(int i=0;i<n;i++){
		System.out.println("Enter Student Details:");
		System.out.println("Enter name of student:");
		sc.nextLine();
		String naam=sc.nextLine();
		System.out.println("Enter Cgpa,gpa and sem respectively:");
		float cgg=sc.nextFloat();
		float gpp=sc.nextFloat();
		short semm=sc.nextShort();
		System.out.println("Enter year month and date:");
		int y=sc.nextInt();
		int m=sc.nextInt();
		int d=sc.nextInt();
		GregorianCalendar gc=new GregorianCalendar(y,m-1,d);
        s[i]=new Student(naam,gc,semm,cgg,gpp);
        }
	    Student si=new Student();
	    System.out.println("1.Sort by Sem & CGPA\n2.Sort by Name\n3.List All the names starting from a particular character");
	    System.out.println("4.List Student names which contain a particular sub-string");
	    System.out.println("5.Replace Name with Initial");
	    char choice=sc.next().charAt(0);
	    sc.nextLine();
	    
	    while(choice == '1' || choice =='2'|| choice=='3' || choice=='4' || choice =='5'){
	    if(choice =='1'){
	    si.sortsem(s,n);}
	    if(choice=='2'){
	    si.sortname(s,n);}
	    if(choice=='3'){
	    	System.out.println("Enter character");
	    	char str=sc.nextLine().charAt(0);
			si.partChar(s,n,str);
        }
	    if(choice=='4'){
	    	System.out.println("Enter substring:");
	    	String str=sc.nextLine();
	    	si.partSubString(s, n, str);
	    }
	    if(choice =='5'){
	    	System.out.println("Converting Names of each object");
	    	si.initials(s,n);

	    }
	  
	    System.out.println("Enter new choice:");
	    choice=sc.next().charAt(0);
	    sc.nextLine();
	
}
}
}
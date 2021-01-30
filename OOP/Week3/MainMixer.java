import java.util.Scanner;
class MainMixer{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Mixer A=new Mixer(n);
		A.accept();
		A.display();
		n=sc.nextInt();
		Mixer B=new Mixer(n);
		B.accept();
        B.display();
        Mixer C=A.mix(B);
        C.display();
	}


}
class Mixer{
	int a[];
	public Mixer(int n){
		a=new int[n];
	}
	Scanner sc=new Scanner(System.in);

	void accept(){
		for(int i=0;i<a.length;i++)
		{

			a[i]=sc.nextInt();
		}
	}
	void display(){
		for(int i=0;i<a.length;i++)
		{

			System.out.print(a[i]+" ");
		}
		System.out.println();
	}


    Mixer mix(Mixer b){
    	int npeace=a.length+b.a.length;
    	Mixer peace=new Mixer(npeace);
    	int i,j,k;
    	i=0;
    	j=0;
    	k=0;
    	int flag=0;
    	while(j<a.length && k<b.a.length){
    		if(a[j]<b.a[k]){
    			peace.a[i++]=a[j++];}
    		else
    			peace.a[i++]=b.a[k++];
    		if(k==b.a.length){
    			flag=1;
    			break;
    		}
            if(j==a.length){
            	flag=2;
            	break;
            }
    		}
    	if(flag==1){
        while (j < a.length) 
            peace.a[i++] = a[j++]; 
      }
        // Store remaining elements of second array 
       if(flag==2){
        while (k < b.a.length) 
            peace.a[i++] = b.a[k++];
    } 
    return peace;
}
}
 
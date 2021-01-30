class Asd{
int af[];
int bf[];
void fib(){
	int a=0;
	int b=1;
	int c=1;
	int i=0;
	while(a<=100){
	af[i]=a;
	c=a+b;
	a=b;
	b=c;
	i++;
}
}
void primed(){
int num;
 for(num = 1; num <= 100;num++)
  {
  	count=0;
    for (i = 2; i <= num/2; i++)
    {
  	if(num%i == 0)
  	{
  		break;
	}
    }
    if(count == 0 && num!= 1 )
    {
	
    }  

}
}
}
class Mythread implements Runnable{
	Thread thrd;
	Asd asss;
	Mythread(String name,asss){
		this.asss=asss;
		thrd=new Thread(this,name);
		thrd.start();
	}
	public void run(){
		if(thrd.getName().equals(First)){
			asss.fib();
		}
		else{
			asss.prime();
		}
	}

}
class fibprime{
	public static void main(String args[]){
		Asd ass=new Asd();
		Mythread mt1=new Mythread("First",ass);
		Mythread mt2=new Mythread("Second",ass);
	} 
}

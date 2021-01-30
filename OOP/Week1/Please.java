
/**
 * Write a description of Please here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Please {
    public static boolean isPrime(int num){
        int k=0;
        for(int i=2;i<=num/2;i++){
           if(num%i==0){
             k=1;
             break;
            }
            
        }
        if(k==1){
            return true;
        }
        else
        {
            return false;
        }
    }
public static void main(String args[]){
    int count=0;
    while(count<6){
        for(int i=2;;i++){
    boolean b=isPrime(i);
    if(b==false)
    {
     //   System.out.println("Number is not prime");
     System.out.println(i);
     count++;
     if(count==5){
       break;  
        }
    }
    else{
     continue;
        //System.out.println("Number is prime");   
    }
   }
   if(count==5){
       break;  
        }
}
}
}

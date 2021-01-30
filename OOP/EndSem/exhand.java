import java.util.Scanner;
public class exhand
{ public static void main(String args[])
{ Scanner sc=new Scanner(System.in);
int x=sc.nextInt() ;
try {
try { if ( x==1)
throw new NullPointerException();
else if(x==2)
throw new InterruptedException();
else
throw new RuntimeException();
}
catch(RuntimeException e)
{ System.out.println("Runtime Exception caught");
//return;//idhar return daala then innertry ends and main end s dono print nahi hoga
}
catch(InterruptedException e)
{ System.out.println("Interrupted Exception caught");
}
System.out.println("inner try ends");
return;
}
catch(Exception e)
{ System.out.println(" Exception caught");
}
finally
{ System.out.println("from finally");
}
System.out.println("main ends");
}
}
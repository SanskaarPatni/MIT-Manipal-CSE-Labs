import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int t;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        for(int y=0;y<t;y++){
          sc.nextLine();
            String a=sc.next();
            String b=sc.next();
            if(a.length()!=b.length()){
                boolean f=false;
                System.out.println(f);
            }
            else{  
                HashMap<Character,Integer>mapA=new HashMap<Character,Integer>();
                HashMap<Character,Integer>mapB=new HashMap<Character,Integer>();
                
                for(int i=0;i<a.length();i++){
                    if(mapA.containsKey(a.charAt(i))){
                        mapA.put(a.charAt(i),mapA.get(a.charAt(i))+1);
                        }
                    else{
                        mapA.put(a.charAt(i),1);
                    }
                      if(mapB.containsKey(b.charAt(i))){
                        mapB.put(b.charAt(i),mapB.get(b.charAt(i))+1);
                        }
                    else{
                        mapB.put(b.charAt(i),1);
                    }
                }
                if(mapA==mapB){
                    boolean f=true;
                    System.out.println(f);
                    }
          }
    }
}
}
WRRRRRRRRRONG
//import java.io.*;
import java.util.*;

public class Solution {
    public static boolean value(String a,String b){
        if(a.length()!=b.length()){
                return false;
            }
            else if(a.equals(b)==true){
              return false;
            }
            else{  
                int count =0;
                int prev=-1;int curr=-1;
                for(int i=0;i<a.length();i++){
                    if(a.charAt(i)!=b.charAt(i)){
                        count++;
                        if (count > 2) {
                     return false;
                        }
                prev = curr; 
                curr = i; 
                        
                    }
             }
                if (count == 2 && 
                a.charAt(prev) == b.charAt(curr) && 
                a.charAt(curr) == b.charAt(prev)){
                  return true;}
            } 
        return false;
    }
        
    

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int t;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        for(int y=0;y<t;y++){
            String a=new String();
            String b=new String();
            sc.next();
            a=sc.nextLine();
            b=sc.nextLine();
            boolean p=value(a,b);
            System.out.println(p);
}
}
}
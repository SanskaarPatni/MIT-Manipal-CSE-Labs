import java.io.*;
import java.util.*;

public class Solution {
   public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        String x="abcdefghijklmnopqrstuvwxyz";
        HashMap<Integer,Character>map=new HashMap<Integer,Character>();
        for(int i=0;i<26;i++){
            map.put(i+1,x.charAt(i));
        }
        int t=sc.nextInt();
        for(int e=0;e<t;e++){
        int n=sc.nextInt();
        int k=sc.nextInt();
    
        StringBuilder a=new StringBuilder();
        StringBuilder b=new StringBuilder();
        int count=0; 
        int j=26;
        int p=1;
        int i;
        for(i=0;i<n-k+1;i++){
            a.append(map.get(j));
            b.append(map.get(p));
        }
        for(i=n-k+1;i<n;i++){
            a.append(map.get(--j));
            b.append(map.get(++p));
        }
        System.out.println(a.reverse().toString());
        System.out.println(b.toString());
    }
 }
}




    Scanner sc=new Scanner(System.in);
    double N=sc.nextDouble();
    int a[N];
    for(int i=0;i<N;i++){
        a[i]=sc.nextInt();
    }
    HashMap<Integer,Integer>map= new HashMap<Integer,Integer>();
    for(int i=0;i<N;i++){
        if(map.containsKey()){
            map.get(i)=map.get(i)+1;
        }
            
    }

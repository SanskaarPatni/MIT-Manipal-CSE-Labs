import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
WRONGGGGG

public class Solution {
    public static void main(String args[] ) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner sc=new Scanner(System.in);
        String a=new String();
        a=sc.nextLine();
        char p=sc.next().charAt(0);
        int pj=sc.nextInt();
        int flag=0;
        int d=a.indexOf(p);
        if(d==-1){
            flag=1;
            System.out.println(-1);
        }
        if(flag==0){
        int count=0;
        while(d!=-1){
        d=a.indexOf(p,d+1);
            count++;
        }
        int f=pj/count;
        int k=f*(a.length())+a.indexOf(p)+1;
        System.out.println(k);
        }
}
}
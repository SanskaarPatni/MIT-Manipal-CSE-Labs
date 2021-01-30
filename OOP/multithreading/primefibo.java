import java.io.*;
import java.io.PipedWriter;
import java.io.PipedReader;
class fibonacci extends Thread
{
            PipedWriter fw=new PipedWriter();
            public PipedWriter getwrite()
            {
                        return fw;
            }
            public void run()
            {
                        super.run();
                        fibo();
            }
            int f(int n)
            {
                        if(n<2)
                                    return n;
                                    else
                                                return f(n-1)+f(n-2);
            }
            void fibo()
            {
                        for(int i=2,fibv=0;(fibv=f(i))<100000;i++)
                        {
                                    try{
                                   
                                    fw.write(fibv);
                                    }
                                    catch(IOException e){
                                    }
                        }
            }
}
class receiver extends Thread
{
            PipedReader fibr,primer;
            public receiver(fibonacci fib,prime pr)throws IOException
            {
                        fibr=new PipedReader(fib.getwrite());
                        primer=new PipedReader(pr.getwrite());
            }
            public void run()
            {
                        int p=0,f=0;
                        try{
                       
                        p=primer.read();
                        f=fibr.read();
                        }
                        catch(IOException e)
                        {
                        }
                        while(true)
                        {
                                    try
                                                {
                                   
                                    if(p==f){
                                   
                                                System.out.println ("Match:"+p);
                                                p=primer.read();
                                                f=fibr.read();
                                    }
                                    else if(f<p)
                                                f=fibr.read();
                                                else
                                                            p=primer.read();
                        }catch(IOException e)
                        {System.exit(-1);
                        }
                        }
                       
            }
}
class prime extends Thread
{
            PipedWriter pw=new PipedWriter();
            public PipedWriter getwrite()
            {
                        return pw;
            }
            public void run()
            {
                        super.run();
                        prim();
            }
            public void prim()
            {
                        for(int i=2;i<100000;i++)
                        {
                                    if(isprime(i))
                                    {
                                                try{
                                                            pw.write(i);
                                                }
                                                catch(IOException e){
                                                }
                                    }
                        }
            }
            boolean isprime(int n)
            {
                        boolean p=true;
                        int s=(int)Math.sqrt(n);
                        for(int i=2;i<=s;i++)
                        {
                                    if(n%i==0)
                                                p=false;
                        }
                        return p;
            }
}
class primefibo
{
            public static void main (String[] args)throws IOException {
                        fibonacci fi=new fibonacci();
                        prime pri=new prime();
                        receiver r=new receiver(fi,pri);
                        fi.start();
                        pri.start();
                        r.start();
                       
}
}
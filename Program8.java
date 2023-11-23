import java.util.Scanner;

class Caller 
{
    static synchronized void callMeSynchronized(String msg) 
    {
        System.out.print("[ " + msg);
        try 
        {
            Thread.sleep(1000);
        } 
        catch (InterruptedException e) 
        {
            System.out.println(e);
        }
        System.out.println(" ]");
    }

    static void callMeWithoutSynchronized(String msg) 
    {
        System.out.print("[ " + msg);
        try 
        {
            Thread.sleep(1000);
        } 
        catch (InterruptedException e) 
        {
            System.out.println(e);
        }
        System.out.println(" ]");
    }
}

class Call extends Thread 
{
    private String msg;
    private int n;

    Call(String m, int n) 
    {
        this.msg = m;
        this.n = n;
    }

    public void run() 
    {
        if(n == 1)
        
        {
            Caller.callMeSynchronized(msg);
        }
        else
        
        {
            Caller.callMeWithoutSynchronized(msg);
        }

    }
}

public class test 
{
    public static void main(String[] args) 
    
    {
        Scanner ip = new Scanner(System.in);
        System.out.println("For Synchronized press 1 and without that press 2");
        int n = ip.nextInt();
        if(n == 1)
        
        {
            Call obj1 = new Call("learn", n);
            Call obj2 = new Call("java", n);
            Call obj3 = new Call("language", n);

            obj1.start();
            obj2.start();
            obj3.start();
        }
        else
        
        {
            Call obj1 = new Call("learn", n);
            Call obj2 = new Call("java", n);
            Call obj3 = new Call("language", n);

            obj1.start();
            obj2.start();
            obj3.start();
        }
    }
}

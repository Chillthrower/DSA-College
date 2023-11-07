import java.util.Scanner;

public class Hello 
{
    public static void main(String[] args) throws InterruptedException 
    {
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter number of inputs: ");
        int n = ip.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter input:");

        for (int i = 0; i < n; i++) 
        {
            arr[i] = ip.nextInt();
        }

        System.out.print("Entered input: ");
        for (int i = 0; i < n; i++) 
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        Runnable even = new Even(arr);
        Runnable odd = new Odd(arr);

        Thread run1 = new Thread(even);
        Thread run2 = new Thread(odd);

        run1.start();
        run2.start();

        // Check if run1 and run2 are alive
        if (run1.isAlive()) 
        {
            System.out.println("Thread run1 is alive.");
        }
        if (run2.isAlive()) 
        {
            System.out.println("Thread run2 is alive.");
        }

        // Use join to wait for run1 and run2 to complete
        run1.join();
        run2.join();

        System.out.println("Both threads have completed their tasks.");
    }
}

class Even implements Runnable 
{
    private int[] arr;

    public Even(int[] arr) 
    {
        this.arr = arr;
    }

    public synchronized void run() 
    {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) 
        {
            if (arr[i] % 2 == 0) 
            {
                sum += arr[i];
            }
        }
        System.out.println("answer even : " + sum);
    }
}

class Odd implements Runnable 
{
    private int[] arr;

    public Odd(int[] arr) 
    {
        this.arr = arr;
    }

    public void run() 
    {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) 
        {
            if (arr[i] % 2 != 0) 
            {
                sum += arr[i];
            }
        }
        System.out.println("answer odd : " + sum);
    }
}

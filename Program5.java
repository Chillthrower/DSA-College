import java.util.Random;

class RandomNumberGenerator implements Runnable 
{
    @Override
    public void run() 
    {
        Random random = new Random();
        try 
        {
            while (true) 
            {
                int randomNumber = random.nextInt(100); 
                System.out.println("Generated: " + randomNumber);
                Thread.sleep(1000); 
            }
        } catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

class SquareCalculator implements Runnable 
{
    private int number;

    public SquareCalculator(int number) 
    {
        this.number = number;
    }

    @Override
    public void run() 
    {
        try 
        {
            while (true) 
            {
                System.out.println("Square: " + (number));
                number = number * number;
                Thread.sleep(1000); 
            }
        } catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

class CubeCalculator implements Runnable 
{
    private int number;

    public CubeCalculator(int number) 
    {
        this.number = number;
    }

    @Override
    public void run() 
    {
        try 
        {
            while (true) 
            {
                System.out.println("Cube: " + (number));
                number = number * number * number;
                Thread.sleep(1000); 
            }
        } catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

public class MultiThreadedApplication 
{
    public static void main(String[] args) 
    {
        Thread generatorThread = new Thread(new RandomNumberGenerator());
        Thread squareThread = new Thread(new SquareCalculator(2)); 
        Thread cubeThread = new Thread(new CubeCalculator(2)); 

        generatorThread.start();
        squareThread.start();
        cubeThread.start();
    }
}

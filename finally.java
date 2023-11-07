public class FinallyExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            // Code that may throw an exception
            int result = 10 / 0; // This will throw an ArithmeticException
        } 
        catch (ArithmeticException e) 
        {
            System.err.println("ArithmeticException: Division by zero");
        } 
        finally 
        {
            // Code in the finally block is executed even after an exception
            System.out.println("This will always be executed.");
        }
    }
}

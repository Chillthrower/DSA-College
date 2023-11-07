public class TryCatchExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            int numerator = 10;
            int denominator = 0;
            int result = numerator / denominator; // This will throw an ArithmeticException
        } 
        catch (ArithmeticException e) 
        {
            System.err.println("ArithmeticException: Division by zero");
        }
    }
}

public class ThrowExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            throw new IllegalArgumentException("Custom exception message");
        } 
        catch (IllegalArgumentException e) 
        {
            System.err.println("IllegalArgumentException: " + e.getMessage());
        }
    }
}

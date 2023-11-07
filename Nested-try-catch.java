public class NestedTryExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            try 
            {
                int[] arr = new int[3];
                int value = arr[4]; // This will throw an ArrayIndexOutOfBoundsException
            } 
            catch (ArrayIndexOutOfBoundsException e) 
            {
                System.err.println("Inner catch: ArrayIndexOutOfBoundsException");
            }
        } 
        catch (Exception e) 
        {
            System.err.println("Outer catch: Exception");
        }
    }
}

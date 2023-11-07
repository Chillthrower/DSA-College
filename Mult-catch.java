public class MultipleCatchExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            int[] arr = new int[3];
            int value = arr[4]; // This will throw an ArrayIndexOutOfBoundsException
        } 
        catch (ArrayIndexOutOfBoundsException e) 
        {
            System.err.println("ArrayIndexOutOfBoundsException: Index out of bounds");
        } 
        catch (NullPointerException e) 
        {
            System.err.println("NullPointerException: " + e.getMessage());
        }
    }
}

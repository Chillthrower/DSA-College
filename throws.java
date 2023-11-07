public class ThrowsExample 
{
    public static void main(String[] args) 
    {
        try 
        {
            processFile("file.txt");
        } 
        catch (FileNotFoundException e) 
        {
            System.err.println("FileNotFoundException: " + e.getMessage());
        }
    }

    public static void processFile(String fileName) throws FileNotFoundException 
    {
        if (!fileName.equals("valid.txt")) 
        {
            throw new FileNotFoundException("File not found: " + fileName);
        }
    }
}

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class RnW
{
    public static void main(String[] args)
    {
        Scanner obj = new Scanner(System.in);
        System.out.println("enter the name of the file : ");
        String name = obj.nextLine();
        File myfile = new File(name + ".txt");
        try 
        {
            if (myfile.createNewFile()) 
            {
                System.out.println("File created: " + myfile.getName()); 
                FileWriter myWriter = new FileWriter(myfile);
                System.out.println("enter the ip you want to write : ");
                String ip = obj.nextLine();
                myWriter.write(ip);
                myWriter.close();
                System.out.println("written Successfully");
                System.out.println("Reading the file : ");
                Scanner myReader = new Scanner(myfile);
                while (myReader.hasNextLine()) 
                {
                    String data = myReader.nextLine();
                    System.out.println(data);    
                }
                myReader.close();
            }
            else
            {
                System.out.println("file already exists ; " + myfile.getName());
            }
        } 
        catch (IOException e) 
        {
            System.out.print("an error has occured : ");
            e.printStackTrace();
        }
    }
}

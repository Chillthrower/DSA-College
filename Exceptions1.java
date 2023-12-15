import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class JTest 
{
    public static void main(String[] args) 
    {
        try (Scanner scanner = new Scanner(System.in)) 
        {
            System.out.print("Enter the number of elements (n): ");
            int n = scanner.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) 
            {
                System.out.print("Enter element " + (i + 1) + ": ");
                arr[i] = scanner.nextInt();
            }

            System.out.print("Enter the index to access an element: ");
            int index = scanner.nextInt();

            try 
            {
                int smallest = Arrays.stream(arr).min().orElseThrow();
                Arrays.stream(arr).mapToObj(element ->"Element " + element + " divided by the smallest element (" + smallest + ") is " + element / smallest).forEach(System.out::println);
            } 
            catch (ArithmeticException e) 
            {
                System.err.println("ArithmeticException: Division by zero.");
            }

            try 
            {
                int elementAtIndex = arr[index];
                System.out.println("Element at index " + index + ": " + elementAtIndex);
            } 
            catch (ArrayIndexOutOfBoundsException e) 
            {
                System.err.println("ArrayIndexOutOfBoundsException: Index out of bounds.");
            }
        } 
        catch (InputMismatchException e) 
        {
            System.err.println("InputMismatchException: Invalid input. Please enter integers.");
        }
    }
}

import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandlingExample 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        try 
        {
            System.out.print("Enter the number of elements (n): ");
            int n = scanner.nextInt();
            int[] arr = new int[n];

            // Read elements into the array
            for (int i = 0; i < n; i++) 
            {
                System.out.print("Enter element " + (i + 1) + ": ");
                arr[i] = scanner.nextInt();
            }

            System.out.print("Enter the index to access an element: ");
            int index = scanner.nextInt();

            // Handle exceptions for dividing each element by the smallest element
            try 
            {
                int smallest = findSmallest(arr);
                for (int i = 0; i < n; i++) 
                {
                    int result = divideBySmallest(arr[i], smallest);
                    System.out.println("Element " + arr[i] + " divided by the smallest element (" + smallest + ") is " + result);
                }
            } 
            catch (ArithmeticException e) 
            {
                System.err.println("ArithmeticException: Division by zero.");
            }

            // Handle exceptions for accessing an element by the specified index
            try 
            {
                int elementAtIndex = getElementAtIndex(arr, index);
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
        finally 
        {
            scanner.close();
        }
    }

    // Helper method to find the smallest element in the array
    private static int findSmallest(int[] arr) 
    {
        int smallest = arr[0];
        for (int i = 1; i < arr.length; i++) 
        {
            if (arr[i] < smallest) 
            {
                smallest = arr[i];
            }
        }
        return smallest;
    }

    // Helper method to divide an element by the smallest element
    private static int divideBySmallest(int element, int smallest) 
    {
        if (smallest == 0) 
        {
            throw new ArithmeticException("Division by zero");
        }
        return element / smallest;
    }

    // Helper method to get an element at the specified index
    private static int getElementAtIndex(int[] arr, int index) 
    {
        if (index < 0 || index >= arr.length) 
        {
            throw new ArrayIndexOutOfBoundsException("Index out of bounds");
        }
        return arr[index];
    }
}

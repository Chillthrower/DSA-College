import java.util.Scanner;

public class Student 
{
    private String usn;
    private String name;
    private String branch;
    private String phone;

    // Constructor to initialize the Student object
    public Student(String usn, String name, String branch, String phone) 
    {
        this.usn = usn;
        this.name = name;
        this.branch = branch;
        this.phone = phone;
    }

    // Method to display the details of the Student
    public void displayDetails() 
    {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        System.out.println("Branch: " + branch);
        System.out.println("Phone: " + phone);
        System.out.println("-----------------------------");
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

        // Create an array to store n Student objects
        Student[] students = new Student[n];

        // Input details for each student and create Student objects
        for (int i = 0; i < n; i++) 
        {
            System.out.println("\nEnter details for Student " + (i + 1) + ":");
            System.out.print("Enter USN: ");
            String usn = scanner.next();
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.print("Enter Branch: ");
            String branch = scanner.next();
            System.out.print("Enter Phone: ");
            String phone = scanner.next();

            // Create a new Student object and store it in the array
            students[i] = new Student(usn, name, branch, phone);
        }

        // Display details of all students
        System.out.println("\nDetails of all Students:");
        for (Student student : students) 
        {
            student.displayDetails();
        }

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}

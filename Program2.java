import java.util.Scanner;

// Super class: Staff
class Staff 
{
    private int staffId;
    private String name;
    private String phone;
    private double salary;

    // Constructor to initialize Staff object
    public Staff(int staffId, String name, String phone, double salary) 
    {
        this.staffId = staffId;
        this.name = name;
        this.phone = phone;
        this.salary = salary;
    }

    // Display details of Staff
    public void displayDetails() 
    {
        System.out.println("Staff ID: " + staffId);
        System.out.println("Name: " + name);
        System.out.println("Phone: " + phone);
        System.out.println("Salary: $" + salary);
    }
}

// Subclass 1: Teaching
class Teaching extends Staff 
{
    private String domain;
    private String publications;

    // Constructor to initialize Teaching object
    public Teaching(int staffId, String name, String phone, double salary, String domain, String publications) 
    {
        super(staffId, name, phone, salary);
        this.domain = domain;
        this.publications = publications;
    }

    // Display details of Teaching staff
    @Override
    public void displayDetails() 
    {
        super.displayDetails();
        System.out.println("Domain: " + domain);
        System.out.println("Publications: " + publications);
        System.out.println("-----------------------------");
    }
}

// Subclass 2: Technical
class Technical extends Staff 
{
    private String skills;

    // Constructor to initialize Technical object
    public Technical(int staffId, String name, String phone, double salary, String skills) 
    {
        super(staffId, name, phone, salary);
        this.skills = skills;
    }

    // Display details of Technical staff
    @Override
    public void displayDetails() 
    {
        super.displayDetails();
        System.out.println("Skills: " + skills);
        System.out.println("-----------------------------");
    }
}

// Subclass 3: Contract
class Contract extends Staff 
{
    private int period;

    // Constructor to initialize Contract object
    public Contract(int staffId, String name, String phone, double salary, int period) 
    {
        super(staffId, name, phone, salary);
        this.period = period;
    }

    // Display details of Contract staff
    @Override
    public void displayDetails() 
    {
        super.displayDetails();
        System.out.println("Contract Period: " + period + " months");
        System.out.println("-----------------------------");
    }
}

public class StaffManagementSystem 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        // Creating arrays to store staff objects
        Teaching[] teachingStaff = new Teaching[3];
        Technical[] technicalStaff = new Technical[3];
        Contract[] contractStaff = new Contract[3];

        // Taking user input to create Teaching staff objects
        System.out.println("Enter details for Teaching Staff:");
        for (int i = 0; i < 3; i++) 
        {
            System.out.println("\nEnter details for Teaching Staff " + (i + 1) + ":");
            System.out.print("Enter Staff ID: ");
            int staffId = scanner.nextInt();
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.print("Enter Phone: ");
            String phone = scanner.next();
            System.out.print("Enter Salary: ");
            double salary = scanner.nextDouble();
            System.out.print("Enter Domain: ");
            String domain = scanner.next();
            System.out.print("Enter Publications: ");
            String publications = scanner.next();

            teachingStaff[i] = new Teaching(staffId, name, phone, salary, domain, publications);
        }

        // Taking user input to create Technical staff objects
        System.out.println("\nEnter details for Technical Staff:");
        for (int i = 0; i < 3; i++) 
        {
            System.out.println("\nEnter details for Technical Staff " + (i + 1) + ":");
            System.out.print("Enter Staff ID: ");
            int staffId = scanner.nextInt();
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.print("Enter Phone: ");
            String phone = scanner.next();
            System.out.print("Enter Salary: ");
            double salary = scanner.nextDouble();
            System.out.print("Enter Skills: ");
            String skills = scanner.next();

            technicalStaff[i] = new Technical(staffId, name, phone, salary, skills);
        }

        // Taking user input to create Contract staff objects
        System.out.println("\nEnter details for Contract Staff:");
        for (int i = 0; i < 3; i++) 
        {
            System.out.println("\nEnter details for Contract Staff " + (i + 1) + ":");
            System.out.print("Enter Staff ID: ");
            int staffId = scanner.nextInt();
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.print("Enter Phone: ");
            String phone = scanner.next();
            System.out.print("Enter Salary: ");
            double salary = scanner.nextDouble();
            System.out.print("Enter Contract Period (in months): ");
            int period = scanner.nextInt();

            contractStaff[i] = new Contract(staffId, name, phone, salary, period);
        }

        // Displaying details of all staff objects
        System.out.println("\nDetails of Teaching Staff:");
        for (Teaching staff : teachingStaff) 
        {
            staff.displayDetails();
        }

        System.out.println("\nDetails of Technical Staff:");
        for (Technical staff : technicalStaff) 
        {
            staff.displayDetails();
        }

        System.out.println("\nDetails of Contract Staff:");
        for (Contract staff : contractStaff) 
        {
            staff.displayDetails();
        }

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}

// Java Interface: Resume
interface Resume 
{
    void biodata();
}

// Teacher class implementing Resume interface
class Teacher implements Resume 
{
    private String personalInformation;
    private String qualification;
    private String experience;
    private String achievements;

    // Constructor for Teacher class
    public Teacher(String personalInformation, String qualification, String experience, String achievements) 
    {
        this.personalInformation = personalInformation;
        this.qualification = qualification;
        this.experience = experience;
        this.achievements = achievements;
    }

    // Implementing biodata method from Resume interface
    @Override
    public void biodata() 
    {
        System.out.println("Teacher Biodata:");
        System.out.println("Personal Information: " + personalInformation);
        System.out.println("Qualification: " + qualification);
        System.out.println("Experience: " + experience);
        System.out.println("Achievements: " + achievements);
        System.out.println("-----------------------------");
    }
}

// Student class implementing Resume interface
class Student implements Resume 
{
    private String personalInformation;
    private String result;
    private String discipline;

    // Constructor for Student class
    public Student(String personalInformation, String result, String discipline) 
    {
        this.personalInformation = personalInformation;
        this.result = result;
        this.discipline = discipline;
    }

    // Implementing biodata method from Resume interface
    @Override
    public void biodata() 
    {
        System.out.println("Student Biodata:");
        System.out.println("Personal Information: " + personalInformation);
        System.out.println("Result: " + result);
        System.out.println("Discipline: " + discipline);
        System.out.println("-----------------------------");
    }
}

// Main class to test the program
public class ResumeGenerator 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        // Taking user input for Teacher
        System.out.println("Enter details for Teacher:");
        System.out.print("Enter Personal Information: ");
        String teacherInfo = scanner.nextLine();
        System.out.print("Enter Qualification: ");
        String teacherQualification = scanner.nextLine();
        System.out.print("Enter Experience: ");
        String teacherExperience = scanner.nextLine();
        System.out.print("Enter Achievements: ");
        String teacherAchievements = scanner.nextLine();

        Teacher teacher = new Teacher(teacherInfo, teacherQualification, teacherExperience, teacherAchievements);

        // Taking user input for Student
        System.out.println("\nEnter details for Student:");
        System.out.print("Enter Personal Information: ");
        String studentInfo = scanner.nextLine();
        System.out.print("Enter Result: ");
        String studentResult = scanner.nextLine();
        System.out.print("Enter Discipline: ");
        String studentDiscipline = scanner.nextLine();

        Student student = new Student(studentInfo, studentResult, studentDiscipline);

        // Calling biodata method for Teacher and Student
        teacher.biodata();
        student.biodata();

        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}

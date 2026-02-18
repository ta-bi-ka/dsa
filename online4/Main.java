import java.util.ArrayList;
import java.util.Scanner;

// Class to represent a course
class Course {
    int courseID;
    String courseName;
    int seatCapacity;
    ArrayList<Student> enrolledStudents;

    // Constructor to initialize course
    public Course(int courseID, String courseName, int seatCapacity) {
        this.courseID = courseID;
        this.courseName = courseName;
        this.seatCapacity = seatCapacity;
        this.enrolledStudents = new ArrayList<>();
    }

    // Method to check if the course has available seats
    public boolean hasAvailableSeats() {
        return enrolledStudents.size() < seatCapacity;
    }

    // Method to enroll a student in the course
    public boolean enrollStudent(Student student) {
        if (hasAvailableSeats() && !isStudentEnrolled(student)) {
            enrolledStudents.add(student);
            return true;
        }
        return false;
    }

    // Method to drop a student from the course
    public boolean dropStudent(Student student) {
        return enrolledStudents.remove(student);
    }

    // Check if a student is already enrolled in this course
    public boolean isStudentEnrolled(Student student) {
        return enrolledStudents.contains(student);
    }

    // Method to display course details and enrolled students
    public void displayCourseDetails() {
        System.out.println("Course ID: " + courseID + ", Name: " + courseName + ", Capacity: " + seatCapacity + ", Enrolled: " + enrolledStudents.size());
        if (enrolledStudents.isEmpty()) {
            System.out.println("No students enrolled.");
        } else {
            for (Student student : enrolledStudents) {
                System.out.println("Student ID: " + student.studentID + ", Name: " + student.studentName);
            }
        }
    }
}

// Class to represent a student
class Student {
    int studentID;
    String studentName;

    // Constructor to initialize student
    public Student(int studentID, String studentName) {
        this.studentID = studentID;
        this.studentName = studentName;
    }
}

// Main class to drive the program
public class Main {

    private static ArrayList<Course> courses = new ArrayList<>();
    private static ArrayList<Student> students = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        // Create some sample courses
        courses.add(new Course(1, "Mathematics", 30));
        courses.add(new Course(2, "Computer Science", 40));
        courses.add(new Course(3, "Physics", 25));

        boolean running = true;
        while (running) {
            // Display user menu
            System.out.println("Menu:");
            System.out.println("1. Enroll a New Student in a Course");
            System.out.println("2. Enroll Existing Student in a Course");
            System.out.println("3. Drop Student from a Course");
            System.out.println("4. Display All Courses with Enrolled Students");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // Consume newline character

            switch (choice) {
                case 1:
                    enrollNewStudent();
                    break;
                case 2:
                    enrollExistingStudent();
                    break;
                case 3:
                    dropStudent();
                    break;
                case 4:
                    displayAllCourses();
                    break;
                case 5:
                    running = false;
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid option, please try again.");
            }
        }
    }

    // Enroll a new student
    public static void enrollNewStudent() {
        System.out.print("Enter Student ID: ");
        int studentID = scanner.nextInt();
        scanner.nextLine();  // Consume newline character
        System.out.print("Enter Student Name: ");
        String studentName = scanner.nextLine();
        System.out.print("Enter Course ID: ");
        int courseID = scanner.nextInt();
        
        Student student = new Student(studentID, studentName);
        students.add(student);

        Course course = getCourseByID(courseID);
        if (course != null) {
            if (course.enrollStudent(student)) {
                System.out.println("Student enrolled successfully.");
            } else {
                System.out.println("Failed to enroll: Course might be full or student already enrolled.");
            }
        } else {
            System.out.println("Invalid Course ID.");
        }
    }

    // Enroll an existing student
    public static void enrollExistingStudent() {
        System.out.print("Enter Student ID: ");
        int studentID = scanner.nextInt();
        System.out.print("Enter Course ID: ");
        int courseID = scanner.nextInt();

        Student student = getStudentByID(studentID);
        if (student != null) {
            Course course = getCourseByID(courseID);
            if (course != null) {
                if (course.enrollStudent(student)) {
                    System.out.println("Student enrolled successfully.");
                } else {
                    System.out.println("Failed to enroll: Course might be full or student already enrolled.");
                }
            } else {
                System.out.println("Invalid Course ID.");
            }
        } else {
            System.out.println("Invalid Student ID.");
        }
    }

    // Drop a student from a course
    public static void dropStudent() {
        System.out.print("Enter Student ID: ");
        int studentID = scanner.nextInt();
        System.out.print("Enter Course ID: ");
        int courseID = scanner.nextInt();

        Student student = getStudentByID(studentID);
        if (student != null) {
            Course course = getCourseByID(courseID);
            if (course != null) {
                if (course.dropStudent(student)) {
                    System.out.println("Student dropped successfully.");
                } else {
                    System.out.println("Student is not enrolled in this course.");
                }
            } else {
                System.out.println("Invalid Course ID.");
            }
        } else {
            System.out.println("Invalid Student ID.");
        }
    }

    // Display all courses with enrolled students
    public static void displayAllCourses() {
        for (Course course : courses) {
            course.displayCourseDetails();
            System.out.println();
        }
    }

    // Helper methods to get student and course by ID
    public static Student getStudentByID(int studentID) {
        for (Student student : students) {
            if (student.studentID == studentID) {
                return student;
            }
        }
        return null;
    }

    public static Course getCourseByID(int courseID) {
        for (Course course : courses) {
            if (course.courseID == courseID) {
                return course;
            }
        }
        return null;
    }
}

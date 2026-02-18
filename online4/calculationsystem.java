 
 
 
 
 public class Quiz {
    private String quizTitle;
    private double penaltyPerWrong;

    public Quiz(String quizTitle, double penaltyPerWrong) {
        this.quizTitle = quizTitle;
        this.penaltyPerWrong = penaltyPerWrong;
    }

    public String getQuizTitle() {
        return quizTitle;
    }

    public double getPenaltyPerWrong() {
        return penaltyPerWrong;
    }
}

public class Student {

    private String studentName;
    private int[] wrongAnswers;

    public Student(String name, int quizCount) {
        this.studentName = name;
        wrongAnswers = new int[quizCount];
    }

    public String getStudentName() {
        return studentName;
    }

    public void setWrongAnswer(int quizIndex, int value) {
        wrongAnswers[quizIndex] = value;
    }

    public double calculatePenaltyForQuiz(int index, Quiz[] quizzes) {
        return wrongAnswers[index] * quizzes[index].getPenaltyPerWrong();
    }

    public double getTotalPenalty(Quiz[] quizzes) {
        double total = 0;
        for (int i = 0; i < wrongAnswers.length; i++) {
            total += calculatePenaltyForQuiz(i, quizzes);
        }
        return total;
    }

    public void displayDetails(Quiz[] quizzes) {
        System.out.println("Student Name: " + studentName);

        for (int i = 0; i < wrongAnswers.length; i++) {
            System.out.println(
                quizzes[i].getQuizTitle() + " Penalty: " +
                calculatePenaltyForQuiz(i, quizzes)
            );
        }

        System.out.println("Total Penalty: " + getTotalPenalty(quizzes));
        System.out.println();
    }
}
import java.util.Scanner;

public class calculationsystem {

    public static void main(String[] args) {

        int studentCount = Integer.parseInt(args[0]);
        int quizCount = Integer.parseInt(args[1]);

        Scanner sc = new Scanner(System.in);

        Quiz[] quizzes = new Quiz[quizCount];
        Student[] students = new Student[studentCount];

        // Taking Quiz Input
        for (int i = 0; i < quizCount; i++) {
            System.out.print("Enter Quiz Title: ");
            String title = sc.nextLine();

            System.out.print("Enter Penalty Per Wrong Answer: ");
            double penalty = sc.nextDouble();
            sc.nextLine();

            quizzes[i] = new Quiz(title, penalty);
        }

        // Taking Student Input
        for (int i = 0; i < studentCount; i++) {
            System.out.print("Enter Student Name: ");
            String name = sc.nextLine();

            students[i] = new Student(name, quizCount);

            for (int j = 0; j < quizCount; j++) {
                int wrong;
                do {
                    System.out.print("Wrong answers in " + quizzes[j].getQuizTitle() + ": ");
                    wrong = sc.nextInt();
                } while (wrong < 0);

                students[i].setWrongAnswer(j, wrong);
            }
            sc.nextLine();
        }

        // Command Loop
        while (true) {
            System.out.print("Enter Command: ");
            String command = sc.nextLine();

            if (command.equals("exit")) {
                break;
            }

            else if (command.startsWith("display")) {
                String name = command.split(" ")[1];

                if (name.equals("all")) {
                    for (Student s : students) {
                        if (s != null)
                            s.displayDetails(quizzes);
                    }
                } else {
                    for (Student s : students) {
                        if (s != null && s.getStudentName().equals(name)) {
                            s.displayDetails(quizzes);
                        }
                    }
                }
            }

            else if (command.startsWith("delete")) {
                String name = command.split(" ")[1];

                for (int i = 0; i < students.length; i++) {
                    if (students[i] != null &&
                        students[i].getStudentName().equals(name)) {

                        students[i] = null;
                        System.out.println(name + " deleted.");
                    }
                }
            }
        }
    }
}

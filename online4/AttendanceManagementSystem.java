
import java.util.Scanner;

// Class to represent an Employee
class Employee {
    int employeeId;
    String name;
    int daysPresent;

    public Employee(int employeeId, String name, int daysPresent) {
        this.employeeId = employeeId;
        this.name = name;
        this.daysPresent = daysPresent;
    }

    // Method to increase attendance
    public void markAttendance() {
        daysPresent++;
    }

    // Method to decrease attendance
    public void correctAttendance() {
        if (daysPresent > 0) {
            daysPresent--;
        } else {
            System.out.println("Attendance cannot be less than zero.");
        }
    }

    // Method to display employee info
    public void displayEmployeeInfo() {
        System.out.println("Employee ID: " + employeeId + ", Name: " + name + ", Days Present: " + daysPresent);
    }
}

// Class to represent a Department
class Department {
    int departmentId;
    Employee[] employees;
    int employeeCount;

    public Department(int departmentId, int maxEmployees) {
        this.departmentId = departmentId;
        this.employees = new Employee[maxEmployees];
        this.employeeCount = 0;
    }

    // Method to add an employee
    public void addEmployee(int employeeId, String name, int daysPresent) {
        if (employeeCount < employees.length) {
            employees[employeeCount] = new Employee(employeeId, name, daysPresent);
            employeeCount++;
        } else {
            System.out.println("Maximum number of employees reached for this department.");
        }
    }

    // Method to display department info
    public void displayDepartmentInfo() {
        if (employeeCount == 0) {
            System.out.println("No employees registered.");
        } else {
            System.out.println("Department ID: " + departmentId);
            for (int i = 0; i < employeeCount; i++) {
                employees[i].displayEmployeeInfo();
            }
        }
    }

    // Method to find an employee by ID
    public Employee findEmployee(int employeeId) {
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].employeeId == employeeId) {
                return employees[i];
            }
        }
        return null; // Employee not found
    }
}

// Main class to control the flow of the program
public class AttendanceManagementSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Department[] departments = new Department[10];
        int departmentCount = 0;

        // Read the number of departments
        System.out.print("Enter number of departments: ");
        int numDepartments = scanner.nextInt();

        // Create departments and add employees
        for (int i = 0; i < numDepartments; i++) {
            System.out.print("Enter number of employees for Department " + (i + 1) + ": ");
            int numEmployees = scanner.nextInt();
            Department department = new Department(i + 1, 50); // Max 50 employees per department
            departments[i] = department;

            for (int j = 0; j < numEmployees; j++) {
                System.out.println("Enter details for Employee " + (j + 1));
                System.out.print("Enter Employee ID: ");
                int employeeId = scanner.nextInt();
                scanner.nextLine(); // Consume newline character
                System.out.print("Enter Employee Name: ");
                String name = scanner.nextLine();
                System.out.print("Enter Days Present: ");
                int daysPresent = scanner.nextInt();
                department.addEmployee(employeeId, name, daysPresent);
            }
        }

        // Menu loop for user actions
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Mark Attendance (Increase Days)");
            System.out.println("2. Correct Attendance (Decrease Days)");
            System.out.println("3. Display All Department Info");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter Department ID: ");
                    int markDeptId = scanner.nextInt();
                    System.out.print("Enter Employee ID: ");
                    int markEmpId = scanner.nextInt();
                    if (markDeptId <= numDepartments && markDeptId > 0) {
                        Employee employee = departments[markDeptId - 1].findEmployee(markEmpId);
                        if (employee != null) {
                            employee.markAttendance();
                            System.out.println("Attendance marked successfully.");
                        } else {
                            System.out.println("Employee not found.");
                        }
                    } else {
                        System.out.println("Invalid department ID.");
                    }
                    break;
                case 2:
                    System.out.print("Enter Department ID: ");
                    int correctDeptId = scanner.nextInt();
                    System.out.print("Enter Employee ID: ");
                    int correctEmpId = scanner.nextInt();
                    if (correctDeptId <= numDepartments && correctDeptId > 0) {
                        Employee employee = departments[correctDeptId - 1].findEmployee(correctEmpId);
                        if (employee != null) {
                            employee.correctAttendance();
                            System.out.println("Attendance corrected successfully.");
                        } else {
                            System.out.println("Employee not found.");
                        }
                    } else {
                        System.out.println("Invalid department ID.");
                    }
                    break;
                case 3:
                    for (int i = 0; i < numDepartments; i++) {
                        departments[i].displayDepartmentInfo();
                    }
                    break;
                case 4:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}

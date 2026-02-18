import java.util.Scanner;

// Class to represent a Book
class Book {
    int bookId;
    String title;
    boolean isAvailable;

    public Book(int bookId, String title, boolean isAvailable) {
        this.bookId = bookId;
        this.title = title;
        this.isAvailable = isAvailable;
    }
}

// Class to represent a Library Branch
class LibraryBranch {
    int branchId;
    Book[] books;
    int bookCount;

    public LibraryBranch(int branchId, int maxBooks) {
        this.branchId = branchId;
        this.books = new Book[maxBooks];
        this.bookCount = 0;
    }

    // Method to add a book to the branch
    public void addBook(int bookId, String title, boolean isAvailable) {
        if (bookCount < books.length) {
            books[bookCount] = new Book(bookId, title, isAvailable);
            bookCount++;
        } else {
            System.out.println("Maximum number of books reached for this branch.");
        }
    }

    // Method to display the details of the books in the branch
    public void displayBranchInfo() {
        if (bookCount == 0) {
            System.out.println("No books available.");
        } else {
            System.out.println("Branch ID: " + branchId);
            for (int i = 0; i < bookCount; i++) {
                System.out.println("Book ID: " + books[i].bookId + ", Title: " + books[i].title + ", Available: " + books[i].isAvailable);
            }
        }
    }

    // Method to borrow a book by ID
    public boolean borrowBook(int bookId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookId == bookId && books[i].isAvailable) {
                books[i].isAvailable = false;
                System.out.println("Book borrowed successfully.");
                return true;
            }
        }
        System.out.println("Book is not available.");
        return false;
    }

    // Method to return a book by ID
    public boolean returnBook(int bookId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].bookId == bookId && !books[i].isAvailable) {
                books[i].isAvailable = true;
                System.out.println("Book returned successfully.");
                return true;
            }
        }
        System.out.println("Book was not borrowed.");
        return false;
    }
}

// Main class to handle user input and program flow
public class LibraryManagementSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LibraryBranch[] branches = new LibraryBranch[10];
        int branchCount = 0;

        // Read the number of branches
        System.out.print("Enter number of branches: ");
        int numBranches = scanner.nextInt();

        // Create library branches and add books
        for (int i = 0; i < numBranches; i++) {
            System.out.print("Enter number of books for Branch " + (i + 1) + ": ");
            int numBooks = scanner.nextInt();
            LibraryBranch branch = new LibraryBranch(i + 1, 20);  // Max 20 books per branch
            branches[i] = branch;

            for (int j = 0; j < numBooks; j++) {
                System.out.println("Enter details for Book " + (j + 1));
                System.out.print("Enter Book ID: ");
                int bookId = scanner.nextInt();
                scanner.nextLine(); // Consume newline character
                System.out.print("Enter Book Title: ");
                String title = scanner.nextLine();
                System.out.print("Is the book available? (true/false): ");
                boolean isAvailable = scanner.nextBoolean();
                branch.addBook(bookId, title, isAvailable);
            }
        }

        // Program loop for user actions
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Borrow a Book");
            System.out.println("2. Return a Book");
            System.out.println("3. Display All Branch Info");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter Branch ID: ");
                    int borrowBranchId = scanner.nextInt();
                    System.out.print("Enter Book ID: ");
                    int borrowBookId = scanner.nextInt();
                    if (borrowBranchId <= numBranches && borrowBranchId > 0) {
                        branches[borrowBranchId - 1].borrowBook(borrowBookId);
                    } else {
                        System.out.println("Invalid branch ID.");
                    }
                    break;
                case 2:
                    System.out.print("Enter Branch ID: ");
                    int returnBranchId = scanner.nextInt();
                    System.out.print("Enter Book ID: ");
                    int returnBookId = scanner.nextInt();
                    if (returnBranchId <= numBranches && returnBranchId > 0) {
                        branches[returnBranchId - 1].returnBook(returnBookId);
                    } else {
                        System.out.println("Invalid branch ID.");
                    }
                    break;
                case 3:
                    for (int i = 0; i < numBranches; i++) {
                        branches[i].displayBranchInfo();
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

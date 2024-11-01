import Book.Book;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class App {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of books: ");
        int n = sc.nextInt();
        Book[] books = new Book[n];


        double max_price = 0.0;
        int pos1 = 0, pos2 = 0;

        for (int i = 0; i < n; i++) {
            books[i] = new Book(); // Exception in thread "main" java.lang.NullPointerException: Cannot invoke "Book.Book.input()" because "<local3>[<local8>]" is null      at App.main(App.java:23)
            System.out.println("### Book number " + (i + 1));
            books[i].input();

            if (books[i].getPrice() > max_price) {
                max_price = books[i].getPrice();
                pos1 = i;
            }
            if (books[i].getName().equals("Java OOP")) {
                // books_2.add
                pos2 = i;
            }
        }



        // In ra thong tin n cuon sach vua nhap
        System.out.println();
        for (int i = 0; i < n; i++) {
            System.out.println("Book " + (i + 1) + ": " + books[i]);
        }
        System.out.println();

        // In ra cuon sach co gia cao nhat
        System.out.println("Sach co gia cao nhat la sach thu " + (pos1+1) + ": " + books[pos1]);

        // In ra cuon sach co ten la Java OOP
        if (pos2 != -1) {
            System.out.println("Sach co ten Java OOP la sach thu " + (pos2+1) + ": " + books[pos2]);
        }
        else {
            System.out.println("Khong ton tai sach");
        }

        System.out.println();

        // Sap xep tang dan theo quantity
        System.out.println("Sap xep danh sach tang dan theo quantity:");

        Arrays.sort(books, Comparator.comparingInt(Book::getQuantity));

        for (int i = 0; i < n; i++) {
            System.out.println("Book " + (i+1) + ": " + books[i]);
        }

        System.out.println();

        // Sap xep giam dan theo price
        System.out.println("Sap xep danh sach giam dan theo price:");

        Arrays.sort(books, Comparator.comparingDouble(Book::getPrice).reversed());

        for (int i = 0; i < n; i++) {
            System.out.println("Book " + (i+1) + ": " + books[i]);
        }



        sc.close();
    }
}

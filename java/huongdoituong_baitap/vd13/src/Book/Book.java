package Book;

import java.util.Scanner;

public class Book {
    private String name = "";
    private double price = 0.0;
    private int quantity = 0;

    public Book() {

    }
    public Book(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public void setName(String name) {
        this.name = name;
    }
    public void setPrice(double price) {
        this.price = Math.max(price, 0.0);
    }
    public void setQuantity(int quantity) {
        this.quantity = Math.max(quantity, 0);
    }

    public String getName() {
        return name;
    }
    public double getPrice() {
        return price;
    }
    public int getQuantity() {
        return quantity;
    }


    @Override
    public String toString() {
        return "Name: " + name + ", Price: " + price + ", Quantity: " + quantity;
    }


    public void input() {

        Scanner sc2 = new Scanner(System.in);

        System.out.print("Enter name: ");
        String name = sc2.nextLine();
        this.name = name;

        System.out.print("Enter price: ");
        double price = sc2.nextDouble();
        this.price = price;

        System.out.print("Enter quantity: ");
        int quantity = sc2.nextInt();
        this.quantity = quantity;

        // sc2.close(); -> returns error
        // at java.base/java.util.Scanner.nextLine(Scanner.java:1677)
        // at Book.Book.input(Book.java:51)
        // at java.base/java.util.Scanner.nextLine(Scanner.java:1677)
        // at Book.Book.input(Book.java:51)
        // at App.main(App.java:23)
    }
}
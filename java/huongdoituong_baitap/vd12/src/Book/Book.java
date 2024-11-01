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
        this.price = price;
    }
    public void setQuantity(int quantity) {
        this.quantity = quantity;
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

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name: ");
        String name = sc.nextLine();
        this.name = name;

        System.out.print("Enter price: ");
        double price = sc.nextDouble();
        this.price = price;

        System.out.print("Enter quantity: ");
        int quantity = sc.nextInt();
        this.quantity = quantity;

        sc.close();
    }
}
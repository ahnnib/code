package Person;

import java.util.Scanner;

public class Person {
    private String name;
    private int age;
    private int address;

    public Person() {}
    public Person(String name, int age, int address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public int getAddress() {
        return address;
    }

    public void setAddress(int address) {
        this.address = address;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return String.format("%s, %d, %d", name, age, address);
    }


    public void input() {

        Scanner sc = new Scanner(System.in);

        System.out.print("Name: ");
        name = sc.nextLine();
        System.out.print("Age: ");
        age = sc.nextInt();
        System.out.print("Address: ");
        address = sc.nextInt();

        sc.close();
    }


    public int getYearOfBirth() {
        return 2024 - age;
    }
    public String getUpperName() {
        return name.toUpperCase();
    }
    public boolean checkAge(int age) {
        return this.age >= age;
    }
}

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

    public void input() {
        Scanner sc = new Scanner(System.in);
    }

}

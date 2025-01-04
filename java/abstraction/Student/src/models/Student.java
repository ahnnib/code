package models;

import java.util.Scanner;

public abstract class Student {
    private String masv = "-";
    private String name = "-";
    private int age = 0;

    public Student() {}
    public Student(String _masv, String _name, int _age) {
        masv = _masv;
        name = _name;
        age = _age;
    }

    public String getMasv() {
        return masv;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public void setMasv(String masv) {
        this.masv = masv;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return String.format("%s, %s, %d", this.masv, this.name, this.age);
    }

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("masv: ");
        masv = sc.nextLine();
        System.out.print("name: ");
        name = sc.nextLine();
        System.out.print("age: ");
        age = sc.nextInt();
        sc.close();
    }
    public abstract float calculateAverage();
}
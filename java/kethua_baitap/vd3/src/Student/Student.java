package Student;

import Person.Person;
import java.util.Scanner;

public class Student extends Person {
    private String StudentID = "";
    private String nameSchool = "";

    public Student() {}
    public Student(String name, int age, int address, String StudentID, String nameSchool) {
        super(name, age, address);
        this.StudentID = StudentID;
        this.nameSchool = nameSchool;
    }

    public String getStudentID() {
        return StudentID;
    }
    public String getNameSchool() {
        return nameSchool;
    }
    public void setStudentID(String studentID) {
        this.StudentID = studentID;
    }
    public void setNameSchool(String nameSchool) {
        this.nameSchool = nameSchool;
    }

    @Override
    public String toString() {
        return String.format("%s, %d, %d, %s, %s", getName(), getAge(), getAddress(), StudentID, nameSchool);
    }

    @Override
    public void input() {

        super.input();

        Scanner sc = new Scanner(System.in);

        System.out.print("StudentID: ");
        StudentID = sc.nextLine();
        System.out.print("nameSchool: ");
        nameSchool = sc.nextLine();
        sc.close();
    }



    public boolean checkStudentID() {

        if (StudentID.length() <= 4) {
            return false;
        }

        String prefix = StudentID.substring(0, 4);
        return prefix.equals("23IT");
    }
}
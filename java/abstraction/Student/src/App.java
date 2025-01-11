import models.*;

public class App {
    public static void main(String[] args) {
        Student s = new StudentIT("24A501", "sdkfj", 18, 95, 98);
        Student s1 = new StudentBA("BA01", "sdfkjw", 21, 23, 25);
        Student s2 = new StudentIT("24A502", "mfdjmd", 19, 45, 44);

        StudentManager T = new StudentManager();
        T.addStudent(s);
        T.addStudent(s1);
        T.addStudent(s2);

        T.sortByScore();
        T.displayAllStudents();
        System.out.println("===");

        T.sortByAge();
        T.displayAllStudents();
        System.out.println("===");

        T.removeStudent("24A501");
        T.displayAllStudents();
        System.out.println("===");

        T.addStudent(s);
        T.editStudent("BA059999", s1);
        T.displayAllStudents();
        System.out.println("===");

        System.out.println(T.findStudent(25));
        System.out.println(T.findStudent(21));
        System.out.println(T.findStudent("BA01"));
        System.out.println(T.findStudent("BA059999"));
    }
}
package models;

import interfaces.*;
import java.util.*;

public class StudentManager implements IManager {
    private final ArrayList<Student> students = new ArrayList<>();

    @Override
    public void addStudent(Student student) {
        if (!(student instanceof Student)) {
            throw new IllegalArgumentException("\"student\" not instanceof Student.");
        }
        students.add(student);
    }

    @Override
    public void editStudent(String masv, Student student) {
        for (Student s : students) {
            if (s.getMasv().equals(student.getMasv())) {
                s.setMasv(masv);
            }
        }
    }

    @Override
    public void removeStudent(String masv) {
        for (int i = 0; i < students.size(); i++) {
            if (students.get(i).getMasv().equals(masv)) {
                students.remove(i);
                return;
            }
        }
    }

    @Override
    public Student findStudent(String masv) {
        for (Student s : students) {
            if (s.getMasv().equals(masv)) {
                return s;
            }
        }
        return null;
    }

    @Override
    public void sortByAge() {
        students.sort(Comparator.comparingInt(Student::getAge));
    }

    @Override
    public void sortByScore() {
        // throw new UnsupportedOperationException("Not supported yet.");
        students.sort(Comparator.comparingDouble(Student::calculateAverage));
    }

    @Override
    public ArrayList<Student> findStudent(int age) {
        ArrayList<Student> lst = new ArrayList<>();
        for (Student s : students) {
            if (s.getAge() == age) {
                lst.add(s);
            }
        }
        return lst;
    }

    @Override
    public void displayAllStudents() {
        for (Student s : students) {
            System.out.println(s);
        }
    }
}
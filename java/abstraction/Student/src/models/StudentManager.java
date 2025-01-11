package models;

import java.util.ArrayList;
import interfaces.*;

public class StudentManager implements IManager {
    private ArrayList<Student> students;

    @Override
    public void addStudent(Student s) {
        students.add(s);
    }

    @Override
    public void editStudent(String masv, Student student) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'editStudent'");
    }

    @Override
    public void removeStudent(String masv) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'removeStudent'");
    }

    @Override
    public Student findStudent(String masv) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'findStudent'");
    }

    @Override
    public void sortByAge() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'sortByAge'");
    }

    @Override
    public void sortByScore() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'sortByScore'");
    }

    @Override
    public ArrayList<Student> findStudent(int age) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'findStudent'");
    }

    @Override
    public void displayAllStudents() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'displayAllStudents'");
    }
}

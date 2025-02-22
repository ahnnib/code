package models;

import interfaces.*;
import java.util.ArrayList;

public class ClassManager implements IClass {
    private final ArrayList<CClass> classes = new ArrayList<>();

    @Override
    public ArrayList<CClass> getAllClass() {
        return classes;
    }

    @Override
    public ArrayList<CClass> getClassByTeacher(String name) {
        ArrayList<CClass> lst = new ArrayList<>();
        for (CClass c : classes) {
            if (c.getTeacher().equals(name)) {
                lst.add(c);
            }
        }
        return lst;
    }

    @Override
    public ArrayList<CClass> getClassByTime(Time time) {
        ArrayList<CClass> lst = new ArrayList<>();
        for (CClass c : classes) {
            if (c.getTimeStart().compareTime(time) <= 0 && c.getTimeEnd().compareTime(time) >= 0) {
                lst.add(c);
            }
        }
        return lst;
    }

    @Override
    public void addClass(CClass c) {
        classes.add(c);
    }

    @Override
    public void removeClass(CClass c) {
        for (int i = 0; i < classes.size(); i++) {
            if (classes.get(i).equals(c)) {
                classes.remove(i);
                i--;
            }
        }
    }
}
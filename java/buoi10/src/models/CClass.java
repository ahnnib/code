package models;

import java.util.Objects;
import java.util.Scanner;

public class CClass {
    private String teacher = "-";
    private Time timeStart;
    private Time timeEnd;

    public CClass() {}
    public CClass(String _teacher, Time _timeStart, Time _timeEnd) {
        teacher = _teacher;
        timeStart = _timeStart;
        timeEnd = _timeEnd;
    }

    public String getTeacher() {
        return teacher;
    }
    public Time getTimeStart() {
        return timeStart;
    }
    public Time getTimeEnd() {
        return timeEnd;
    }
    public void setTeacher(String teacher) {
        this.teacher = teacher;
    }
    public void setTimeEnd(Time timeEnd) {
        this.timeEnd = timeEnd;
    }
    public void setTimeStart(Time timeStart) {
        this.timeStart = timeStart;
    }

    public void input() {
        Scanner sc = new Scanner(System.in);
        teacher = sc.nextLine();
        timeStart.input();
        timeEnd.input();
    }

    @Override
    public String toString() {
        return teacher + ", " + timeStart.toString() + ", " + timeEnd.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;  // Same reference
        if (obj == null || getClass() != obj.getClass()) return false;  // Null or different class

        CClass c = (CClass) obj;  // Type cast after checks

        return teacher.equals(c.getTeacher()) &&
            timeStart.compareTime(c.getTimeStart()) == 0 &&
            timeEnd.compareTime(c.getTimeEnd()) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(teacher, timeStart, timeEnd);
    }
}
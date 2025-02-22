package models;

import java.util.Scanner;

public class Time {
    private int hour = 0;
    private int minute = 0;
    private int second = 0;

    public Time() {}
    public Time(int _hour, int _minute, int _second) {
        hour = _hour;
        minute = _minute;
        second = _second;
    }

    public int getHour() {
        return hour;
    }
    public int getMinute() {
        return minute;
    }
    public int getSecond() {
        return second;
    }
    public void setHour(int hour) {
        this.hour = hour;
    }
    public void setMinute(int minute) {
        this.minute = minute;
    }
    public void setSecond(int second) {
        this.second = second;
    }

    public void input() {
        Scanner sc = new Scanner(System.in);
        hour = sc.nextInt();
        minute = sc.nextInt();
        second = sc.nextInt();
    }

    @Override
    public String toString() {
        return hour + ":" + minute + ":" + second;
    }

    public int compareTime(Time t) {
        int cmp = Integer.compare(hour, t.getHour());
        if (cmp != 0) return cmp;

        cmp = Integer.compare(minute, t.getMinute());
        if (cmp != 0) return cmp;

        return Integer.compare(second, t.getSecond());
    }
}

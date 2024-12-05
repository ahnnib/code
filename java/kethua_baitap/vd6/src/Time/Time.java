package Time;

public class Time {
    private int hour = 0;
    private int minute = 0;
    private int second = 0;

    public Time() {}
    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
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


    @Override
    public String toString() {
        return hour + ":" + minute + ":" + second;
    }

    public int toSecond() {
        return hour * 3600 + minute * 60 + second;
    }
    public Time toTime(int second) {
        Time t = new Time();
        t.hour = (second / 3600) % 24;
        second %= 3600;
        t.minute = second / 60;
        second %= 60;
        t.second = second;
        return t;
    }


    public void updateTime(Time t) {
        this.hour = t.hour;
        this.minute = t.minute;
        this.second = t.second;
    }
    public void nextSecond() {
        int currentTime = this.toSecond();
        int newTime = currentTime + 1;
        updateTime(toTime(newTime));
    }
    public void nextMinute() {
        int currentTime = this.toSecond();
        int newTime = currentTime + 60;
        updateTime(toTime(newTime));
    }
    public void nextHour() {
        int currentTime = this.toSecond();
        int newTime = currentTime + 3600;
        updateTime(toTime(newTime));
    }
}

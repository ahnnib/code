package Time;

public class Time {
    protected int hour = 0;
    protected int minute = 0;
    protected int second = 0;

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


    public void formatTime() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;

        int extraDays = hour / 24;
        // if (this instanceof DateTime) {
            //     ((DateTime) this).adjustDate(extraDays);
            // }
        if (this instanceof DateTime dateTime) {
            dateTime.adjustDate(extraDays);
        }
        hour %= 24;
    }

    public void nextSecond() {
        this.second += 1;
        formatTime();
    }
    public void nextMinute() {
        this.minute += 1;
        formatTime();
    }
    public void nextHour() {
        this.hour += 1;
        formatTime();
    }
}

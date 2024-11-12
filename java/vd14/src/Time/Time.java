package Time;

public class Time {
    public int hour = 0;
    public int minute = 0;
    public int second = 0;

    public Time() {}
    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
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
    public Time toTime(int t) {
        Time time = new Time();

        time.hour = t / 3600;
        t %= 3600;
        time.minute = t / 60;
        t %= 60;
        time.second = t;

        return time;
    }

    public Time add(Time t) {

        Time newTime = new Time(this.hour, this.minute, this.second);

        newTime.hour += t.hour;
        newTime.minute += t.minute;
        newTime.second += t.second;

        while (newTime.second >= 60) {
            newTime.second -= 60;
            newTime.minute++;
        }
        while (newTime.minute >= 60) {
            newTime.minute -= 60;
            newTime.hour++;
        }
        if (newTime.hour >= 24) {
            newTime.hour %= 24;
        }

        return newTime;
    }
    public Time distance(Time t) {
        int time_1 = this.hour * 3600 + this.minute * 60 + this.second;
        int time_2 = t.hour * 3600 + t.minute * 60 + t.second;

        if (time_2 < time_1) time_2 += 24 * 3600;
        int time = time_2 - time_1;

        Time dist = new Time();
        dist.second = time;
        while (dist.second >= 60) {
            dist.second -= 60;
            dist.minute++;
        }
        while (dist.minute >= 60) {
            dist.minute -= 60;
            dist.hour++;
        }
        if (dist.hour >= 24) {
            dist.hour %= 24;
        }

        return dist;
    }
}
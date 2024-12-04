package Time;

public class DateTime extends Time {
    private int day = 0;
    private int month = 0;
    private int year = 0;

    public DateTime() {}
    public DateTime(int day, int month, int year, int hour, int minute, int second) {
        super(hour, minute, second);
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public void setDay(int day) {
        this.day = day;
    }
    public void setMonth(int month) {
        this.month = month;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public int getDay() {
        return day;
    }
    public int getMonth() {
        return month;
    }
    public int getYear() {
        return year;
    }

    @Override
    public String toString() {
        return year + "/" + month + "/" + day + " " + super.toString();
    }


    @Override
    public int toSecond() {
        return super.toSecond() +
               day * 3600 * 24 +
               month * 3600 * 24 * 30 +
               year * 3600 * 24 * 365;
    }

    public void toDateTime(int second) {
        Time t = new DateTime();
        t = toTime(second);
        second /= 3600;
        second /= 60;
        t.
    }


    public void nextDay() {
        int curTime = this.toSecond();
        curTime += 3600 * 24;
        return toDateTime(curTime);
    }
}

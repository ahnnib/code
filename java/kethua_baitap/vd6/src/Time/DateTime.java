package Time;

public class DateTime extends Time {
    private int day = 1;
    private int month = 1;
    private int year = 0;

    public DateTime() {}
    public DateTime(int year, int month, int day, int hour, int minute, int second) {
        super(hour, minute, second);
        this.year = year;
        this.month = month;
        this.day = day;
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
    public void formatTime() {
        super.formatTime();
        day += days;

        month += (day - 1) / 30;
        day = ((day - 1) % 30) + 1;

        year += (month - 1) / 12;
        month = ((month - 1) % 12) + 1;
    }


    public void nextDay() {
        this.day += 1;
        formatTime();
    }
    public void nextMonth() {
        this.month += 1;
        formatTime();
    }
    public void nextYear() {
        this.year += 1;
        formatTime();
    }
}

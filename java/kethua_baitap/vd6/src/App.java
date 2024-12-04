import Time.Time;

public class App {
    public static void main(String[] args) throws Exception {
        Time t = new Time(21, 53, 54);
        System.out.println(t);
        t.nextSecond();
        while (t.getHour() != 0 || t.getMinute() != 0 || t.getSecond() != 0) {
            t.nextSecond();
            System.out.println(t);
        }
    }
}

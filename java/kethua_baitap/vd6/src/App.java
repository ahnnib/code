import Time.*;

public class App {
    public static void main(String[] args) throws Exception {
        // DateTime t = new DateTime();
        // int cnt = 0;
        // while (t.getYear() < 2) {
        //     t.nextDay();
        //     cnt++;
        // }
        // System.out.println(cnt);
        DateTime t = new DateTime(1, 12, 30, 23, 59, 59);
        t.nextSecond();
        System.out.println(t);
        // 1 12 31 0 0 0
        while (t.getHour() <= 22) t.nextHour();
        System.out.println(t);
        // 1 12 31 23 0 0
        t.nextHour();
        System.out.println(t);
        // 2 1 1 0 0 0

        DateTime t2 = new DateTime(24, 2, 28, 23, 59, 27);
        t2.nextMinute();
        System.out.println(t2);
        // 24 2 29 0 0 27
        t2.nextDay();
        System.out.println(t2);
        // 24 3 1 0 0 27
    }
}

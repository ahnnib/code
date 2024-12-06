import Time.*;

public class App {
    public static void main(String[] args) throws Exception {
        Time t = new DateTime(1, 12, 30, 23, 59, 59);
        t.nextSecond();
        System.out.println(t);
    }
}

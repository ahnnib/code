import Time.Time;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        Time time = new Time(12, 45, 23);
        Time t2 = new Time(21, 32, 43);

        System.out.println(time.distance(t2));
    }
}

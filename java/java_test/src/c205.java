import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();

        System.out.println(100 <= x && x <= 1000 ? "YES" : "NO");
    }
}

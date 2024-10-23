import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String tmp = sc.next();
        char c = tmp.charAt(0);

        System.out.print(c + "\n" + (int)c);
    }
}
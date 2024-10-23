import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (var i = 1; i <= n; i++) {
            System.out.println((i*2) + " " + (i*3));
        }
    }
}
import java.util.Scanner;

public class main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        long n = sc.nextInt();

        System.out.print(n);

        if (n == 10) System.out.print(" bang 10");
        else System.out.print(" khong bang 10");
    }
}

import java.util.Scanner;

public class main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        System.out.println("Phan nguyen cua " + a + " / " + b + " la " + (a / b));
        System.out.println("Phan du cua " + a + " / " + b + " la " + (a % b));
        System.out.println("Trung binh cong cua " + a + " va " + b + " la " + (a + b) / 2.0);

        sc.close();
    }
}

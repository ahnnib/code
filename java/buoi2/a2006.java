package java.sc02;
import java.util.Scanner;

public class a2006 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();

        boolean tang = true, giam = true;
        for (int i = 1; i < n; i++) {
            giam &= (a[i] >= a[i-1]);
        }
        for (int i = 1; i < n; i++) {
            tang &= (a[i] <= a[i-1]);
        }

        System.out.println((tang | giam == true) ? "YES" : "NO");
        sc.close();
    }
}
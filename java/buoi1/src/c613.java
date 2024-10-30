import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int mx = 0, mx1 = 0, mx2 = 0;
        for (int i = 0; i < n; i++) {
            mx = Math.max(mx, a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > mx1) {
                if (a[i] < mx) mx1 = a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > mx2) {
                if (a[i] < mx1) mx2 = a[i];
            }
        }

        if (mx2 == 0) {
            System.out.print("No third largest element");
        }
        else {
            System.out.print(mx2);
        }
    }
}
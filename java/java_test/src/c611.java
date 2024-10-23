import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] a = new int[n];

        int mx = 0, freq = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();

            if (mx < a[i]) {
                mx = a[i];
                freq = 1;
            }
            else if (mx == a[i]) {
                freq++;
            }
        }

        System.out.print(mx + " " + freq);
    }
}
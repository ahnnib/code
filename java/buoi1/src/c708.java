import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();
        long [][] a = new long[m][n];

        long max_sum = (long)-1e18; int index = 0;
        for (int i = 0; i < m; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();

                sum += a[i][j];
            }
            if (sum > max_sum) {
                max_sum = sum;
                index = i;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(a[index][i] + " ");
        }
    }
}
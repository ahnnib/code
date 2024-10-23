import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] a = new int[m][n];

        int odd = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();

                odd += a[i][j] % 2;
            }
        }

        System.out.print(m * n - odd + " " + odd);
    }
}
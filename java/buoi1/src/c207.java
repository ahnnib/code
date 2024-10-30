import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        long[] a = new long[3];
        for (var i = 0; i < 3; i++) a[i] = sc.nextInt();

        Arrays.sort(a);

        boolean kt = a[0] + a[1] > a[2] && a[1] - a[0] < a[2];

        System.out.print(kt ? "YES" : "NO");
    }
}
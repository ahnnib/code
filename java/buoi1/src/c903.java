import java.util.Scanner;

public class c903 {

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt(),
            b = sc.nextInt(),
            c = sc.nextInt();

        Pair[] pairs = {
            new Pair(a, b),
            new Pair(a, c), new Pair(b, c),
            new Pair(a + b, a + c)
        };

        for (Pair i : pairs) {
            System.out.println(gcd(i.first, i.second));
        }

        sc.close();
    }

    public static int gcd(int x, int y) {
        while (y != 0) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
}
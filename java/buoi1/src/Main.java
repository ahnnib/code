import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {


    public static long[][][] dp = new long[10][2][2];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt(), b = sc.nextInt();

        ArrayList<Integer> dig_a = get_dig(a-1), dig_b = get_dig(b);

        for (long[][] array2D : dp) {
            for (long[] array1D : array2D) {
                Arrays.fill(array1D, -1);
            }
        }

        long g2 = f(dig_b, dig_b.size()-1, true, 0, 1);
        long g1 = f(dig_a, dig_a.size()-1, true, 0, 1);

        System.out.println(g2 - g1);

        sc.close();
    }




    public static ArrayList<Integer> get_dig(int x) {

        ArrayList<Integer> dig = new ArrayList<>();

        while (x > 0) {
            dig.add(x % 10);
            x /= 10;
        }
        return dig;
    }




    public static long f(ArrayList<Integer> dig, int vt, boolean tight, int tt, int lz) {

        if (vt < 0) {
            return 1;
        }

        if (dp[vt][tt][lz] != -1 && tight != true) {
            return dp[vt][tt][lz];
        }

        long res = 0;
        int lim = tight == true ? dig.get(vt) : 9;
        for (int d = 0; d <= lim; d++) {

            boolean newTight = d == dig.get(vt) ? tight : false;

            if (lz == 1) {
                if (d == 0) {
                    res += f(dig, vt - 1, newTight, 0, 1);
                }
                else {
                    res += f(dig, vt - 1, newTight, d % 2, 0);
                }
            }
            else if (d % 2 != tt) {
                res += f(dig, vt -1 , newTight, d % 2, 0);
            }
        }

        if (tight != true) {
            dp[vt][tt][lz] = res;
        }

        return res;
    }
}
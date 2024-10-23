import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String X = sc.nextLine();
        String Y = sc.nextLine();

        int nX = X.length(), nY = Y.length();

        if (nY % nX != 0) {
            System.out.print("NO");
            return;
        }

        boolean ok = true;
        for (int i = 0; i + nX <= nY; i += nX) {
            String T = Y.substring(i, i + nX);
            if (X.equals(T) == false) {
                ok = false;
                break;
            }
        }

        System.out.print(ok == true ? "YES" : "NO");
    }
}
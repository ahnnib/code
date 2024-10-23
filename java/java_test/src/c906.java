import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine(), p = sc.nextLine();

        System.out.println(toLowerCase(s));
        System.out.println(toUpperCase(s));
        System.out.println(toLowerCase(p));
        System.out.println(toUpperCase(p));

        sc.close();
    }

    public static String toLowerCase(String s) {
        String res = "";
        for (int i = 0; i < s.length(); i++) {
            if ('A' <= s.charAt(i) && s.charAt(i) <= 'Z') {
                res += (char)(s.charAt(i) + 32);
            }
            else {
                res += s.charAt(i);
            }
        }
        return res;
    }
    public static String toUpperCase(String s) {
        String res = "";
        for (int i = 0; i < s.length(); i++) {
            if ('a' <= s.charAt(i) && s.charAt(i) <= 'z') {
                res += (char)(s.charAt(i) - 32);
            }
            else {
                res += s.charAt(i);
            }
        }
        return res;
    }
}
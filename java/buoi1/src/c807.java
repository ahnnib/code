/*
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        System.out.println(str.toLowerCase());
        System.out.println(str.toUpperCase());
    }
}
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        for (int i = 0; i < str.length(); i++) {
            char new_char = str.charAt(i);
            if ('A' <= new_char && new_char <= 'Z') {
                new_char += 32;
            }
            System.out.print(new_char);
        }

        System.out.println();

        for (int i = 0; i < str.length(); i++) {
            char new_char = str.charAt(i);
            if ('a' <= new_char && new_char <= 'z') {
                new_char -= 32;
            }
            System.out.print(new_char);
        }
    }
}
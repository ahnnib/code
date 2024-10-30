import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        for (String word : str.split("\\s+")) {
            System.out.println(word);
        }
    }
}
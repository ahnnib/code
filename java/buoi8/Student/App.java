public class App {
    public static void main(String[] args) {
        Student s = new StudentIT();
        s.addScore(10);
        s.addScore(15.5);
        s.addScore(6);
        System.out.println(s);
        System.out.println(s.getRank());
    }
}
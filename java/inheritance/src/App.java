import Student.*;

public class App {
    public static void main(String[] args) throws Exception {

        Student s = new Student();
        StudentIT s2 = new StudentIT();

        s.setAge(11);
        System.out.println(s);
        System.out.println(s2);
    }
}

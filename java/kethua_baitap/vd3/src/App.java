import Student.*;

public class App {
    public static void main(String[] args) throws Exception {
        Student s = new Student();

        s.input();

        System.out.println(s);

        System.out.println(s.checkAge(18));
        System.out.println(s.getUpperName());
        System.out.println(s.checkStudentID());
    }
}

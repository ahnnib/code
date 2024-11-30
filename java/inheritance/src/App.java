import Student.Student;
import Student.StudentIT;

public class App {
    public static void main(String[] args) throws Exception {

        Student s = new Student("ID010203", "name", 15);
        Student s3 = new Student("ID010203", "name", 15);
        StudentIT s2 = new StudentIT("ID010203", "namesjsdk", 16, 98, 95);

        System.out.println(s.equals(s3));
        System.out.println(s2);
    }
}

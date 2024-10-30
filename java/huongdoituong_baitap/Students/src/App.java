import Student.Student;

public class App {
    public static void main(String[] args) throws Exception {
        Student sinh_vien = new Student("1313", "aBc", 16);

        sinh_vien.setAge(-1);

        System.out.println(sinh_vien.getAge());
        System.out.println(sinh_vien.getYearOfBirth());
    }
}

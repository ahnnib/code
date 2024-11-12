package Student;

public class Student {
    protected String masv = "";
    private String name = "";
    private int age = 0;

    public Student() {
    }
    public Student(String masv, String name, int age) {
        this.masv = masv;
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return age;
    }
    public String getMasv() {
        return masv;
    }
    public String getName() {
        return name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setMasv(String masv) {
        this.masv = masv;
    }
    public void setName(String name) {
        this.name = name;
    }


    @Override
    public String toString() {
        return String.format("(%s, %s, $d)", masv, name, age);
    }
}
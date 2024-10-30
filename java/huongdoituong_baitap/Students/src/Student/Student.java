package Student;

public class Student {
    private String masv;
    private String name;
    private int age;


    // thuoc tinh mac dinh
    public Student() {
        masv = "";
        name = "";
        age = 1;
    }
    public Student(String masv, String name, int age) {
        this.masv = masv;
        this.name = name;
        this.age = age;
    }


    public void setMasv(String masv) {
        this.masv = masv;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = Math.max(1, age);
    }


    public String getMasv() {
        return masv;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }


    @Override
    public String toString() {
        return "masv = " + masv + ", ten = " + name + ", tuoi = " + age;
    }

    public int getYearOfBirth() {
        return 2024 - age;
    }
    public String getUpperName() {
        return name.toUpperCase();
    }
}

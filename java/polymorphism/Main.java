// SEE MORE: https://chatgpt.com/share/674aaabd-7360-8006-8e1b-4a1491a4dd79
class Student {
    public Student(String string, String string2, int i) {
        //TODO Auto-generated constructor stub
    }

    void study() {
        System.out.println("Studying...");
    }
}

class StudentIT extends Student {
    public StudentIT(String string, String string2, int i, int j, int k) {
        //TODO Auto-generated constructor stub
    }

    @Override
    void study() {
        System.out.println("Studying IT...");
    }

    void code() {
        System.out.println("Coding...");
    }
}

public class Main {
    public static void main(String[] args) {
        Student s = new StudentIT();
        s.study(); // Works, as `study` is defined in `Student`

        // s.code(); // Compile-time error! `code` is not defined in `Student`

        // To access `code`, you need to cast:
        ((StudentIT) s).code(); // Works now!
    }
}

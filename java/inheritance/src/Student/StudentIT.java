package Student;

public class StudentIT extends Student { // ke thua lop Student
    private int scoreCpp;
    private int scoreJava;

    public StudentIT() {
        super(); // khoi tao mac dinh cua lop cha gan nhat
        this.scoreCpp = 0;
        this.scoreJava = 0;
    }

    public StudentIT(String masv, String name, int age, int scoreCpp, int scoreJava) {
        super(masv, name, age); // khoi tao mac dinh tu class Student

        this.scoreCpp = scoreCpp;
        this.scoreJava = scoreJava;
    }

    public int getScoreCpp() {
        return scoreCpp;
    }
    public int getScoreJava() {
        return scoreJava;
    }
    public void setScoreCpp(int scoreCpp) {
        this.scoreCpp = scoreCpp;
    }
    public void setScoreJava(int scoreJava) {
        this.scoreJava = scoreJava;
    }


    @Override
    public String toString() {
        return String.format("(%s, %s, %d, %d, %d)", masv, super.getName(), super.getAge(), scoreCpp, scoreJava);
    }
}

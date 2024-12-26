import java.util.ArrayList;

public class Student {
    private String name = "Unknown";
    private int age = 18;
    private ArrayList<Double> scores = new ArrayList<>();
    public static String university = "Unknown";

    public Student() {}
    public Student(String _name, int _age) {
        name = _name;
        age = _age;
    }


    public void setName(String _name) {
        name = _name;
    }
    public void setAge(int _age) {
        if (_age < 18 || _age > 100) _age = 18;
        age = _age;
    }
    public void setScores(ArrayList<Double> scores) {
        this.scores = scores;
    }
    public static void setUniversity(String university) {
        Student.university = university;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public ArrayList<Double> getScores() {
        return scores;
    }
    public static String getUniversity() {
        return university;
    }


    public void addScore(double score) {
        if (score < 0.0 || score > 10.0) {
            return;
        }
        scores.add(score);
    }
    public double getAverageScore() {
        double sum = 0.0;
        for (double score : scores) {
            sum += score;
        }
        return sum / scores.size();
    }
    public String getRank() {
        double avgScore = getAverageScore();
        if (avgScore >= 9.0) {
            return "A";
        }
        else if (avgScore >= 7.0) {
            return "B";
        }
        else if (avgScore >= 5.0) {
            return "C";
        }
        else {
            return "D";
        }
    }

    @Override
    public String toString() {
        return name + ", " + age + ", " + scores + ", " + university;
    }
}

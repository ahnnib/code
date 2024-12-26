public class StudentIT extends Student {
    private String major = "Unknown";
    private double projectScore = 0.0;

    public StudentIT() {}
    public StudentIT(String _name, int _age, String _major, double _projectScore) {
        super(_name, _age);
        major = _major;
        projectScore = _projectScore;
    }

    public String getMajor() {
        return major;
    }
    public double getProjectScore() {
        return projectScore;
    }
    public void setMajor(String major) {
        this.major = major;
    }
    public void setProjectScore(double projectScore) {
        this.projectScore = projectScore;
    }

    @Override
    public String toString() {
        return super.toString() + ", " + major + ", " + projectScore;
    }

    @Override
    public double getAverageScore() {
        double avgScore = super.getAverageScore();
        return avgScore * 0.7 + projectScore * 0.3;
    }

    @Override
    public String getRank() {
        double score = this.getAverageScore();
        if (score >= 9.0) {
            return "A";
        }
        else if (score >= 7.0) {
            return "B";
        }
        else if (score >= 5.0) {
            return "C";
        }
        else {
            return "D";
        }
    }
}

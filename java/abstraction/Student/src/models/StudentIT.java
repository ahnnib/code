package models;

import java.util.Scanner;

public class StudentIT extends Student {
    private float scoreCpp = 0;
    private float scoreJava = 0;

    public StudentIT() {}
    public StudentIT(String _masv, String _name, int _age, float _scoreCpp, float _scoreJava) {
        super(_masv, _name, _age);
        scoreCpp = _scoreCpp;
        scoreJava = _scoreJava;
    }

    public float getScoreCpp() {
        return scoreCpp;
    }
    public float getScoreJava() {
        return scoreJava;
    }
    public void setScoreCpp(float _scoreCpp) {
        scoreCpp = _scoreCpp;
    }
    public void setScoreJava(float _scoreJava) {
        scoreJava = _scoreJava;
    }

    @Override
    public String toString() {
        return super.toString() + ", " + scoreCpp + ", " + scoreJava;
    }

    @Override
    public void input() {
        Scanner sc = new Scanner(System.in);
        super.input();
        System.out.print("scoreCpp: ");
        scoreCpp = sc.nextInt();
        System.out.print("scoreJava: ");
        scoreJava = sc.nextInt();
        sc.close();
    }

    @Override
    public float calculateAverage() {
        return (scoreCpp + scoreJava) / 2;
    }
}

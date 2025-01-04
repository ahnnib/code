package models;

public class StudentBA extends Student {
    public float scorePm = 0;
    public float scoreBA = 0;

    public StudentBA() {}
    public StudentBA(String _masv, String _name, int _age, float _scorePm, float _scoreBA) {
        super(_masv, _name, _age);
        scorePm = _scorePm;
        scoreBA = _scoreBA;
    }

    public float getScorePm() {
        return scorePm;
    }
    public float getScoreBA() {
        return scoreBA;
    }
    public void setScorePm(float _scorePm) {
        scorePm = _scorePm;
    }
    public void setScoreBA(float _scoreBA) {
        scoreBA = _scoreBA;
    }

    @Override
    public String toString() {
        return super.toString() + ", " + scorePm + ", " + scoreBA;
    }

    @Override
    public float calculateAverage() {
        return (scorePm + scoreBA) / 2;
    }


}
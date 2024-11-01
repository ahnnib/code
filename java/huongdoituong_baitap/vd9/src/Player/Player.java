package Player;

public class Player {

    private String name;
    private int age;
    private int score;
    private int positionX, positionY;


    public Player() {
        name = "";
        age = 0;
        score = 0;
        positionX = positionY = 0;
    }
    public Player(String name, int age, int score, int positionX, int positionY) {
        this.name = name;
        this.age = age;
        this.score = score;
        this.positionX = positionX;
        this.positionY = positionY;
    }


    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        if (age < 0) age = 0;
        this.age = age;
    }
    public void setScore(int score) {
        if (score < 0) score = 0;
        this.score = score;
    }
    public void setPositionX(int positionX) {
        if (positionX < 0) positionX = 0;
        this.positionX = positionX;
    }
    public void setPositionY(int positionY) {
        if (positionY < 0) positionY = 0;
        this.positionY = positionY;
    }



    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public int getScore() {
        return score;
    }
    public int getPositionX() {
        return positionX;
    }
    public int getPositionY() {
        return positionY;
    }


    public void increaseScore() {
        this.score++;
    }
    public void increaseScore(int score) {
        this.score = Math.max(this.score + score, 0);
    }
    public void decreaseScore() {
        this.score--;
    }
    public void decreaseScore(int score) {
        this.score = Math.max(this.score - score, 0);
    }
    public boolean isWinner() {
        return score >= 100;
    }


    @Override
    public String toString() {
        return "Name: " + name + ", Age: " + age + ", Score: " + score + ", posX: " + positionX + ", posY: " + positionY;
    }
}
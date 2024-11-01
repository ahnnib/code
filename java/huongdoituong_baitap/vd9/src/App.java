import Player.*;


public class App {
    public static void main(String[] args) throws Exception {

        Player player_1 = new Player(), player_2 = new Player();

        System.out.println(player_1);
        player_1.increaseScore();
        System.out.println(player_1);
        player_1.increaseScore(3);
        System.out.println(player_1);
    }
}

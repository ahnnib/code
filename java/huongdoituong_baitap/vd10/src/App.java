import Game.*;
import Player.*;

public class App {
    public static void main(String[] args) throws Exception {

        Player player = new Player();
        Game game = new Game();

        game.player_1.increaseScore(3);

        game.swapPlayers();

        System.out.println(game.player_2.getScore());
    }
}

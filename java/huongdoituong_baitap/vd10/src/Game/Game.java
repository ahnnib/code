package Game;

import Player.Player;

public class Game {
    public int id = 0;
    public Player player_1 = new Player();
    public Player player_2 = new Player();


    public Game() {
    }
    public Game(int id) {
        this.id = id;
    }


    public Player getWinner() {
        if (player_1.isWinner() && player_2.isWinner()) {
            return player_1;
        }
        else return null;
    }
    public void resetGame() {
        player_1.setScore(0);
        player_2.setScore(0);
    }
    public void swapPlayers() {
        Player tmp = player_2;
        player_2 = player_1;
        player_1 = tmp;
    }
}

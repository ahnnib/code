package Square;

import Rectangle.Rectangle;
import java.util.Scanner;

public class Square extends Rectangle {

    public Square() {}
    public Square(int side) {
        super(side, side);
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public void input() {
        Scanner sc = new Scanner(System.in);

        super.setWidth(sc.nextInt());
        super.setHeight(sc.nextInt());

        sc.close();
    }
}

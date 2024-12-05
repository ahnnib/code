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
        return "Canh hinh vuong: " + super.getWidth();
    }

    @Override
    public void input() {
        Scanner sc = new Scanner(System.in);

        super.setWidth(sc.nextInt());
        super.setHeight(sc.nextInt());

        sc.close();
    }


    public void setSide(int side) {
        super.setHeight(side);
        super.setWidth(side);
    }
}

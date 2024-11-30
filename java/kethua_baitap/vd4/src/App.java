import Rectangle.Rectangle;
import Square.Square;

public class App {
    public static void main(String[] args) throws Exception {
        Rectangle r = new Rectangle(3, 4);
        Square q = new Square(10);
        System.out.println(q);
        System.out.println(q.getPerimeter());
        System.out.println(q.getArea());

    }

}

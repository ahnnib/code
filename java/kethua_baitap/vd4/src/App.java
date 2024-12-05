import Rectangle.Rectangle;
import Square.Square;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Rectangle r = new Rectangle(3, 4);
        Square q = new Square(10);

        System.out.println(q);
        System.out.println(q.getPerimeter());
        System.out.println(q.getArea());

        q.setSide(20);
        System.out.println(q);
        System.out.println(q.getPerimeter());
        System.out.println(q.getArea());

        System.out.print("Nhap vao canh hinh vuong: ");

        Scanner sc = new Scanner(System.in);

        q.setSide(sc.nextInt());

        System.out.println(q.getPerimeter());
        System.out.println(q.getArea());

        sc.close();
    }

}

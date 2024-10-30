import Rectangles.Rectangles;

public class App {
    public static void main(String[] args) throws Exception {
        Rectangles rectangle = new Rectangles(3, 5);

        System.out.println(rectangle.getArea());
        rectangle.setHeight(35);
        System.out.println(rectangle.getArea());
        System.out.println(rectangle.getPerimeter());
    }
}

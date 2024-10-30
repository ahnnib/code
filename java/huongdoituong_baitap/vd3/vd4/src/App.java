import Triangle.*;

public class App {
    public static void main(String[] args) throws Exception {
        Triangle triangle = new Triangle(2, 3, 5);

        System.out.println(triangle.isRightTriangle());
        triangle.setA(4);
        System.out.println(triangle.isRightTriangle());
    }
}

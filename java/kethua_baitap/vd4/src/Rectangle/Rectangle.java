package Rectangle;

import java.util.Scanner;

public class Rectangle {
    private int width = 0;
    private int height = 0;

    public Rectangle() {}
    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public final void setWidth(int width) {
        this.width = width;
    }
    public final void setHeight(int height) {
        this.height = height;
    }
    public final int getWidth() {
        return width;
    }
    public final int getHeight() {
        return height;
    }

    @Override
    public String toString() {
        return "(" + width + ", " + height + ")";
    }

    public void input() {
        Scanner sc = new Scanner(System.in);
        width = sc.nextInt();
        height = sc.nextInt();
        sc.close();
    }
    public int getArea() {
        return width * height;
    }
    public int getPerimeter() {
        return 2 * (width + height);
    }
}

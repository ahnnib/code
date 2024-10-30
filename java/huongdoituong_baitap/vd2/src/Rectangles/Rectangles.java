package Rectangles;

public class Rectangles {
    private int width;
    private int height;


    public Rectangles() {
        width = 0;
        height = 0;
    }
    public Rectangles(int width, int height) {
        this.width = width;
        this.height = height;
    }


    public void setWidth(int width) {
        this.width = Math.max(0, width);
    }
    public void setHeight(int height) {
        this.height = Math.max(0, height);
    }


    public int getWidth() {
        return width;
    }
    public int getHeight() {
        return height;
    }


    public int getArea() {
        return width * height;
    }
    public int getPerimeter() {
        return width + height << 1;
    }
    public String isSquare() {
        return width == height ? "Yes\n" : "No\n";
    }


    @Override
    public String toString() {
        return "width = " + width + ", height = " + height;
    }
}

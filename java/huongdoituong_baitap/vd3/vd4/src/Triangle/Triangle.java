package Triangle;

public class Triangle {
    private double a = 0, b = 0, c = 0;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void setA(double a) {
        this.a = Math.max(0, a);
    }
    public void setB(double b) {
        this.b = Math.max(0, b);
    }
    public void setC(double c) {
        this.c = Math.max(0, c);
    }
    public void setABC(double a, double b, double c) {
        this.a = Math.max(0, a);
        this.b = Math.max(0, b);
        this.c = Math.max(0, c);
    }


    public double getA() {
        return a;
    }
    public double getB() {
        return b;
    }
    public double getC() {
        return c;
    }


    public double getArea() {
        double p = getPerimeter() / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }
    public double getPerimeter() {
        return a + b + c;
    }
    public boolean isIsoscelesTriangle() {
        return a == b || b == c || a == c;
    }
    public boolean isRightTriangle() {
        double new_a = Math.min(Math.min(a, b), c);
        double new_c = Math.max(Math.max(a, b), c);
        double new_b = a + b + c - new_a - new_c;

        return new_a * new_a + new_b * new_b == new_c * new_c;
    }


    @Override
    public String toString() {
        return "a = " + a + ", b = " + b + ", c = " + c;
    }
}

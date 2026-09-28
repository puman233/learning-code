package 练习;

abstract class Shape{
    abstract double area();
}

class Circle extends Shape{
    private double r;
    Circle(double r){
        this.r = r;
    }

    @Override
    double area() {
        return Math.PI * r * r;
    }
}

class Rectangle extends Shape{
    private double w, h;
    Rectangle(double w, double h){
        this.w = w;
        this.h = h;
    }
    @Override
    double area() {
        return w * h;
    }
}

class Triangle extends Shape{
    private double a;
    private double b;

    public Triangle(double a,double b){
        this.a = a;
        this.b = b;
    }

    @Override
    double area() {
        return a * b * 0.5;
    }
}


class Calculator{   // 计算器类
    public void printArea(Shape s){ // 形参是抽象类类型
        System.out.println("面积：" + s.area());
    }
}


public class _25_ShapeArea {

    public static void main(String[] args) {

        Calculator cal = new Calculator();

        Shape c = new Circle(2.0);
        Shape r = new Rectangle(2.0, 5.0);
        Shape s = new Triangle(3.0, 4.0);

        // 圆
        cal.printArea(c);
        // 长方形
        cal.printArea(r);
        // 三角形
        cal.printArea(s);

    }
}

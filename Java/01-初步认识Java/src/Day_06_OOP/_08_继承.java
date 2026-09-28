package Day_06_OOP;

public class _08_继承 {

/*
Java 继承（子类和超类）
    Java 中可以将属性和方法从一个类继承到另一个类。

我们将"继承概念"分为两类:
    子类 (Subclass) - 子，从另一个类继承的类
    超类 (Superclass) - 父，被继承的类

    要从类继承，请使用 extends关键字。

final 关键字
    如果不希望其他类从类继承，请 final 关键字:

 */

}


class Vehicle {
    Vehicle() {
        System.out.println("Test succeed");
    }
    protected String brand = "理想";        // Vehicle 属性
    public void honk() {                    // Vehicle 方法
        System.out.println("理他干嘛，想停就停!");
    }
}

// Car类（子类）继承了Vehicle类（超类）的属性和方法:
class Car extends Vehicle {
    private String modelName = "666";    // Car 属性
    public static void main(String[] args) {

        // 创建一个 myCar 对象
        Car myCar = new Car();

        Vehicle myVehicle = new Vehicle();
//        System.out.println(myVehicle.modelName);
        // 超类对象不可使用子类变量

        // 在 myCar 对象上调用 honk() 方法（来自 Vehicle 类）
        myCar.honk();

        // 显示 brand 属性的值（来自 Vehicle 类）和来自 Car 类的 modelName 值
        System.out.println(myCar.brand + " " + myCar.modelName);
    }
}

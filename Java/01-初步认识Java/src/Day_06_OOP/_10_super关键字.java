package Day_06_OOP;

public class _10_super关键字 {

/*
Java super 关键字
    在 Java 中，super 关键字用于引用子类的父类。
    super 关键字最常见的用途是消除具有同名方法的超类和子类之间的混淆。

它主要有两种用途:
    访问父类的属性和方法
    调用父类构造函数

 */
    public static void main(String[] args) {
        Dog2 myDog = new Dog2();

        // 访问父类方法
        // 如果子类中有一个与其父类中同名的方法，
        // 您可以使用 super 来调用父类的方法:
        myDog.animalSound();

        // 访问父类属性
        // 如果父类和子类存在同名属性，
        // 您也可以使用 super 来访问父类的属性:
        myDog.printType();

        // 调用父类构造函数
        // 使用 super() 调用父类的 构造函数。
        // 这对于重用初始化代码尤其有用。


    }

}

class Animal2 {
    String type = "Animal2";
    public void animalSound() {
        System.out.println("The animal makes a sound");
    }
    Animal2() {
        System.out.println("Animal2 constructor");
    }
}

class Dog2 extends Animal2 {
    String type = "Dog2";
    public void animalSound() {
        super.animalSound(); // 调用父方法
        System.out.println("The dog says: bow wow");
    }
    public void printType() {
        System.out.println("The type of animal is: " + super.type);
        System.out.println("The type of animal is: " + type);
    }
    Dog2(){
        // 对super()的调用必须是子类构造函数中的第一条语句。
        super();    // 调用父级构造函数
        System.out.println("Dog2 constructor");
    }

}


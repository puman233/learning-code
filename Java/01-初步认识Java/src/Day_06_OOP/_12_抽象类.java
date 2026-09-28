package Day_06_OOP;

public class _12_抽象类 {

/*
抽象类和方法
    数据抽象是隐藏某些细节并仅向用户显示基本信息的过程。
    抽象可以通过abstract classes抽象类或interfaces接口来实现

    abstract 关键字是非访问修饰符，用于类和方法:
        抽象类: 是一个不能用于创建对象的受限类
                （要访问它，必须从另一个类继承）。
        抽象方法: 只能在抽象类中使用，并且它没有主体。
                    主体由子类（继承自）提供。

    抽象也可以通过接口实现

意义：
    因为要实现安全性，要隐藏某些细节并仅显示对象的重要细节。
 */

    public static void main(String[] args) {
        Pig3 myPig = new Pig3(); // 创建 Pig 对象
        myPig.animalSound();
        myPig.sleep();
    }
}

// 抽象类
abstract class Animal3 {
    // 抽象方法（没有主体）
    public abstract void animalSound();
    // 常规方法
    public void sleep() {
        System.out.println("Zzz");
    }
}

// 子类（继承自 Animal3）
class Pig3 extends Animal3 {
    public void animalSound() {
        // 这里提供了 animalSound() 的主体
        System.out.println("The pig says: wee wee");
    }
}



package Day_06_OOP;

public class _14_匿名类 {

/*
匿名类
    匿名类是指没有名称的类。
    它可以同时被创建和使用。

    您通常使用匿名类来重写现有类或接口的方法，
    而无需编写单独的类文件。

当您需要创建一个仅用于一次性使用的简短类时，请使用匿名类。例如:
    无需创建新子类即可重写方法
    快速实现接口
    将少量行为作为对象传递

 */

    public static void main(String[] args) {
        // 重写 makeSound() 的匿名类
        Animal5 myAnimal = new Animal5() {
            public void makeSound() {
                System.out.println("Woof woof");
            }
        }; // 创建对象的代码行必须以分号结束。

        myAnimal.makeSound();

        /*
        从接口创建匿名类
            您还可以使用匿名类来动态实现接口:
         */
        // 实现了 Greeting 接口的匿名类
        Greeting greet = new Greeting() {
            public void sayHello() {
                System.out.println("Hello, World!");
            }
        };

        greet.sayHello();


    }

}

// Normal class
class Animal5 {
    public void makeSound() {
        System.out.println("Animal sound");
    }
}

// Interface
interface Greeting {
    void sayHello();
}



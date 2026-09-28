package Day_06_OOP;

public class _13_接口 {

/*
接口
    Java 中实现abstraction抽象的另一种方法是使用接口。

    An interface 接口是一个完全"抽象类"，用于将相关方法与空实体分组:
        // 接口
        interface Animal {
          public void animalSound(); // 接口方法（没有主体）
          public void run(); // 接口方法（没有主体）
        }

    要访问接口方法，接口必须由另一个具有 implements 关键字
    （而不是extends）的类"实现"（类似于继承）。
    接口方法的主体由"implement"类提供:

    关于接口的说明:
        与抽象类一样，接口不能用于创建对象
        接口方法没有主体-主体由"implement"类提供
        在实现接口时，必须重写其所有方法
        默认情况下，接口方法是 abstract 抽象的和public公共的
        I接口属性默认为 public, static 和 final
        接口不能包含构造函数（因为它不能用于创建对象）

    为了实现安全性-隐藏某些细节，
    只显示对象（接口）的重要细节。

    Java不支持"多重继承"（一个类只能从一个超类继承)
    但是，它可以通过接口实现，因为该类可以实现多个接口。

    要实现多个接口，请用逗号分隔它们


 */

    public static void main(String[] args) {
        Pig4 myPig = new Pig4();  // 创建 Pig 对象
        myPig.animalSound();
        myPig.sleep();
//        myPig.eat(12);
        // （在上面的示例中，不可能在MyMainClass中创建"Animal4"对象）

        // 接口回调
        Food f = new Food();
        f.food(myPig);

        // 多个接口
        DemoClass myObj = new DemoClass();
        myObj.myMethod();
        myObj.myOtherMethod();


    }

}

// 接口
interface Animal4 {
    public void animalSound(); // 接口方法（没有主体）
    public void sleep(); // 接口方法（没有主体）
}

interface Eat{
    public void eat(int n);
}

// 实现接口回调
class Food {
    public void food (Eat e){
        System.out.println("喂食");
        e.eat(12);
        System.out.println("结束");
    }
}

// Pig4 “实现”了 Animal4 接口
class Pig4 implements Animal4, Eat {
    @Override
    public void animalSound() {
        // 这里提供了 animalSound() 的主体
        System.out.println("猪说：小宝宝");
    }
    @Override
    public void sleep() {
        // sleep() 的主体在此处提供
        System.out.println("Zzz");
    }
    @Override
    public void eat(int n) {
        System.out.println("吃掉" + n + "只猪");
    }
}

// 多个接口
interface FirstInterface {
    public void myMethod(); // 接口方法
}

interface SecondInterface {
    public void myOtherMethod(); // 接口方法
}

// 实现继承多个接口
class DemoClass implements FirstInterface, SecondInterface {
    @Override
    public void myMethod() {
        System.out.println("Some text..");
    }
    @Override
    public void myOtherMethod() {
        System.out.println("Some other text...");
    }
}



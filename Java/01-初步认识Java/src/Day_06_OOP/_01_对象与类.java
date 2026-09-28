package Day_06_OOP;

import Day_06_OOP.Other.OtherClass;

public class _01_对象与类 {
    public static void main(String[] args) {

/*
OOP代表面向对象编程。

    过程编程是关于编写对数据执行操作的过程或函数，
    而面向对象编程是创建同时包含数据和函数的对象。

    与过程编程相比，面向对象编程有几个优点:

    OOP 更快更容易执行
    OOP 为程序提供了清晰的结构
    OOP 有助于保持C#代码"不重复自己"，并使代码更易于维护、修改和调试。
    OOP 使得用更少的代码和更短的开发时间创建完全可重用的应用程序成为可能
 */

        /*
        1、类（Class）：
            定义对象的蓝图，包括属性和方法。
            示例：public class Car { ... }

        2、对象（Object）：
            类的实例，具有状态和行为。
            示例：Car myCar = new Car();
         */

        // 类类似于对象构造函数，或用于创建对象的"蓝图"。
        OtherClass myobj = new OtherClass();
        System.out.println(myobj.x);

        OtherClass myobj2 = new OtherClass();
        myobj2.x = 12;
        System.out.println(myobj2.x);

        StuClass stuClass = new StuClass();
        System.out.println(stuClass.name + "'s age is " + stuClass.age);

        stuClass.name = "Teto";
        stuClass.age = 31;
        System.out.println(stuClass.name + "'s age is " + stuClass.age);

    }
}

class StuClass{
    public String name;
    public int age;
    // 是构造函数
    public StuClass() {
        this.name = "Miku";
        this.age = 18;
    }
}


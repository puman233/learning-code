package Day_06_OOP;

import java.util.*;

public class _11_内部类 {

/*
Java 内部类
    在Java中，也可以嵌套类（类中的类）。
    嵌套类的目的是将属于同一类的类分组，
    这使代码更具可读性和可维护性。

要访问内部类，请创建外部类的对象，然后创建内部类的对象:


 */

    public static void main(String[] args) {
        OuterClass myOuter = new OuterClass();
        OuterClass.InnerClass myInner = myOuter.new InnerClass();
        System.out.println(myInner.y + myOuter.x);

        // 内部类访问外部类
        System.out.println(myInner.innerMethod());


        // 不创建外类对象访问内部Static类
        OuterClass.InnerClass3 myInner2 = new OuterClass.InnerClass3();
        System.out.println(myInner2.h);


        // 拙劣的学生系统
        StudentSystem stuSystem = new StudentSystem();
        StudentSystem.Operation opt = stuSystem.new Operation("Miku", 18);
        opt.show();

    }


}

class OuterClass {
    int x = 10;

    class InnerClass {
        int y = 5;
        public int innerMethod() {
            /*
            从内部类访问外部类
                内部类的一个优点是，它们可以访问外部类的属性和方法:
             */
            return x;
        }
    }

    /*
    私有的内部类
        与"常规"类不同，内部类可以是private 私有的或 protected受保护的。
        如果不希望外部对象访问内部类，请将该类声明为private:
     */

    private class InnerClass2 {
        int z = 6;
    }

    /*
    Static 内部类
        内部类也可以是static静态的，
        这意味着您可以在不创建外部类的对象的情况下访问它:

        与 static静态属性和方法一样，
        static静态内部类无权访问外部类的成员。
     */

    static class InnerClass3 {
        int h = 7;
    }
}

class StudentSystem{
    // 内部学生类
    class Student{
        String name;
        int age;

        Student(String name, int age){
            this.name=name;
            this.age=age;
        }

    }

    // 操作方法
    class Operation extends Student {

        // 继承父类构造函数
        Operation(String name, int age) {
            super(name, age);   // 调用父类构造函数
        }
//        public void add(String name, int age){
//            Student stu = new Student(name,age);
//        }

        public void show(){
            System.out.println("name:"+name);
            System.out.println("age:"+age);
        }
    }
}



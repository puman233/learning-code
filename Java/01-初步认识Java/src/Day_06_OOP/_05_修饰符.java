package Day_06_OOP;

//    Abstract
//    abstract 抽象方法属于abstract抽象类，
//    它没有主体。主体由子类提供:
// 抽象类
abstract class Person05 {
    public String fname = "John";
    public int age = 24;
    public abstract void study(); // 抽象方法
}

// 子类（从 Person05 继承）
class Student05 extends Person05 {
    public int graduationYear = 2018;
    public void study() { // 此处提供了抽象方法的主体
        System.out.println("Studying all day long");
    }
}

public class _05_修饰符 {

/*

    访问修饰符 - 控制访问级别
    非访问修饰符 - 不控制访问级别，但提供其他功能

    访问修饰符
        对于 classes，可以使用 public 或 default:
        修饰符	    描述
        public	    该类可由任何其他类访问
        default	    该类只能由同一包中的类访问。
                    在不指定修改器时使用此选项。

    对于属性、方法和构造函数，可以使用以下选项之一:
        修饰符	    描述
        public	    所有类都可以访问该代码
        private	    代码只能在声明的类中访问
        default	    该类只能由同一包中的类访问。
                    在不指定修改器时使用此选项。
        protected	代码可以在相同的包和子类中访问。

    非访问修饰符
    对于类，可以使用final 或 abstract:
        修饰符	    描述
        final	    该类不能被其他类继承
        abstract	该类不能用于创建对象
                    （要访问抽象类，它必须从另一个类继承。）

    对于属性和方法，可以使用以下选项之一:
        修饰符	        描述
        final	        无法覆盖/修改属性和方法
        static	        属性和方法属于类，而不是对象
        abstract	    只能在抽象类中使用，并且只能在方法上使用。
                        该方法没有主体，例如抽象abstract void run();
                        主体由子类（继承自）提供。
        transient	    序列化包含属性和方法的对象时，将跳过属性和方法
        synchronized	方法一次只能由一个线程访问
        volatile	    属性值不是本地缓存的线程，总是从"主内存"中读取


 */

//    Final
//    如果不希望覆盖现有属性值，请将属性声明为 final:
    final int x = 10;
    final double PI = 3.14;

//    Static
//    static 静态方法意味着可以在不创建类对象的情况下访问它，这与public不同:
    // 静态方法
    static void myStaticMethod() {
        System.out.println("Static methods can be called without creating objects");
    }

    // 公共方法
    public void myPublicMethod() {
        System.out.println("Public methods must be called by creating objects");
    }


    public static void main(String[] args) {
        _05_修饰符 myObj = new _05_修饰符();
//        _05_修饰符.x = 50; // 将产生错误:无法为 final 变量赋值
//        _05_修饰符.PI = 25; // 将产生错误:无法为 final 变量赋值
        System.out.println(myObj.x);

        myStaticMethod(); // 调用静态方法
//         myPublicMethod(); 这将输出错误

        // public方法需创建类对象访问
        _05_修饰符 my1 = new _05_修饰符(); // 创建一个 MyClass 的对象
        my1.myPublicMethod(); // 调用公共方法

        // Abstract
        // abstract 抽象方法属于abstract抽象类，它没有主体。主体由子类提供:
        Student05 my2 = new Student05();
        System.out.println("Name: " + my2.fname);
        System.out.println("Age: " + my2.age);
        System.out.println("Graduation Year: " + my2.graduationYear);
        my2.study(); // 调用抽象方法

    }
}

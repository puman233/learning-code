package Day_06_OOP;

public class _04_this {

    /*
    this 在 Java 中，方法或构造函数中的 this 关键字指的是当前对象。

    this 关键字通常用于避免类属性与方法或构造函数参数同名时造成的混淆。

    访问类属性
    有时构造函数或方法会有一个与类变量同名的参数。
    在这种情况下，该参数会暂时隐藏该方法或构造函数内部的类变量。

    要引用类变量而不是参数，可以使用this关键字:


     */

    int x;  // 类变量 x

    // 带一个参数 x 的构造函数
    public _04_this(int x) {
        this.x = x; // this指的是类变量 x
    }

    public static void main(String[] args) {
        // 创建一个 _04_this 对象，并将值 5 传递给构造函数。
        _04_this myObj = new _04_this(5);
        System.out.println("Value of x = " + myObj.x);
    }


}

class Student {
    // 以下是实例变量
    String name;
    int age;

    static String address;  // 类变量
    // 构造函数
    public Student(String name, int age) {  // 实例变量和类变量可以在构造函数中使用
        this.name = name;
        this.age = age;
    }

    // 实例方法
    public void instancePrint(){
        // 但是实例方法就同时能访问实例变量和类变量
        System.out.println("Name is " + name);
        System.out.println("Age is " + age);
        System.out.println("Address is " + address);
    }

    // 类方法
    public static void classPrint() {
        // error是因为实例对象要被new了才能访问
    //    System.out.println("Name is " + name);  // 无法从 static 上下文引用非 static 字段 'name'
        System.out.println("Address is " + address);    // 类方法可以访问类变量
    }

    public static void main(String[] args) {

        // 类方法可直接访问
        Student.classPrint();

        // 实例方法先创建对象后才可访问
        Student n1 = new Student("Miku", 18);
        Student n2 = new Student("Teto", 31);

        // 类变量可通过类名直接访问
        Student.address = "Internet";

        // 实例方法可通过对象访问
        n1.instancePrint();
        n2.instancePrint();


    }
}


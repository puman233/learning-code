package Day_06_OOP;

public class _03_构造函数 {
    int x;  // 类变量 x
    int y;

    // 带一个参数 x 的构造函数
    public _03_构造函数(int x) {
        this.x = x; // 指的是类变量 x
        // x = x;  // 初始化为0
    }

    public static void main(String[] args) {
        // 创建一个 _04_this 对象，并将值 5 传递给构造函数。
        _03_构造函数 myObj = new _03_构造函数(5);
        System.out.println("Value of x = " + myObj.x);
    
        System.out.println("Value of y = " + myObj.y);  // 未初始化，默认值为0
    }
}

// 创建一个 MyClass0 类
class MyClass0 {
    int x;  // 创建类属性
    // 为 MyClass0 类创建一个类构造函数
    public MyClass0() {
        x = 5;  // 设置类属性 x 的初始值
    }
    public static void main(String[] args) {
        MyClass0 myObj = new MyClass0(); // 创建一个 MyClass0 类的对象（这将调用构造函数）
        System.out.println(myObj.x); // 打印 x 的值
    }
}
// 输出 5
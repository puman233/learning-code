/*
 * 多态性
 * 函数重载
 * 运算符重载
 * 接口
 */

namespace _08_OOP_数据处理
{
    class Printdata
    {
        // 函数重载示例print()函数打印不同数据类型
        public void print(int i) {
            Console.WriteLine("Printing int: {0}", i );
        }
        public void print(double f) {
            Console.WriteLine("Printing float: {0}" , f);
        }
        public void print(string s) {
            Console.WriteLine("Printing string: {0}", s);
        }
    }

    // 抽象类
    abstract class Shape {
        public abstract int area();
    }

    // 继承抽象类并实现抽象方法
    class Rectangle:  Shape {
        private int length;
        private int width;

        public Rectangle( int a = 0, int b = 0) {
            length = a;
            width = b;
        }
        public override int area () {
            Console.WriteLine("Rectangle class area :");
            return (width * length);
        }
    }

    // 虚函数
    class Shape2 {
        protected int width, height;

        public Shape2( int a = 0, int b = 0) {
            width = a;
            height = b;
        }
        public virtual int area2() {
            Console.WriteLine("Parent class area :");
            return 0;
        }
    }
    class Rectangle2: Shape2 {
        public Rectangle2( int a = 0, int b = 0): base(a, b) {

        }
        public override int area2 () {
            Console.WriteLine("Rectangle class area :");
            return (width * height);
        }
    }
    class Triangle: Shape2 {
        public Triangle(int a = 0, int b = 0): base(a, b) {
        }
        public override int area2() {
            Console.WriteLine("Triangle class area :");
            return (width * height / 2);
        }
    }
    class Caller {
        public void CallArea(Shape2 sh) {
            int a;
            a = sh.area2();
            Console.WriteLine("Area: {0}", a);
        }
    }

    // 运算符重载
    class Box {
        private double length; // Box 的长度
        private double breadth; // Box 的宽度
        private double height; // Box 的高度

        public double getVolume() {
            return length * breadth * height;
        }
        public void setLength( double len ) {
            length = len;
        }
        public void setBreadth( double bre ) {
            breadth = bre;
        }
        public void setHeight( double hei ) {
            height = hei;
        }

        // 重载 + 运算符以添加两个 Box 对象。
        public static Box operator+ (Box b, Box c) {
            Box box = new Box();
            box.length = b.length + c.length;
            box.breadth = b.breadth + c.breadth;
            box.height = b.height + c.height;
            return box;
        }
        public static bool operator == (Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length == rhs.length &&
                lhs.height == rhs.height &&
                lhs.breadth == rhs.breadth) {
                status = true;
            }
            return status;
        }
        public static bool operator !=(Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length != rhs.length ||
                lhs.height != rhs.height ||
                lhs.breadth != rhs.breadth) {
                status = true;
            }
            return status;
        }
        public static bool operator <(Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length < rhs.length &&
                lhs.height < rhs.height &&
                lhs.breadth < rhs.breadth) {
                status = true;
            }
            return status;
        }
        public static bool operator >(Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length > rhs.length &&
                lhs.height > rhs.height &&
                lhs.breadth > rhs.breadth) {
                status = true;
            }
            return status;
        }
        public static bool operator <=(Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length <= rhs.length &&
                lhs.height <= rhs.height &&
                lhs.breadth <= rhs.breadth) {
                status = true;
            }
            return status;
        }
        public static bool operator >=(Box lhs, Box rhs) {
            bool status = false;
            if (lhs.length >= rhs.length &&
                lhs.height >= rhs.height &&
                lhs.breadth >= rhs.breadth) {
                status = true;
            }
            return status;
        }
        // 重写 Equals 方法
        public override bool Equals(object? obj)
        {
            // 检查是否是同一类型的对象
            if (obj is Box other)
            {
                return this == other;
            }
            return base.Equals(obj);
        }
        // 重写 GetHashCode 方法，确保与 Equals 方法一致
        public override int GetHashCode()
        {
            // 使用长度、宽度和高度来生成哈希值
            return HashCode.Combine(length, height, breadth);
        }
        // 重写 ToString 方法
        public override string ToString() {
            return String.Format("({0}, {1}, {2})", length, breadth, height);
        }
    }


    // 接口
    public interface ITransactions {
        // 接口成员
        void showTransaction();
        double getAmount();
    }
    public class Transaction : ITransactions {
        private string tCode;
        private string date;
        private double amount;

        public Transaction() {
            tCode = " ";
            date = " ";
            amount = 0.0;
        }
        public Transaction(string c, string d, double a) {
            tCode = c;
            date = d;
            amount = a;
        }
        public double getAmount() {
            return amount;
        }
        public void showTransaction() {
            Console.WriteLine("Transaction: {0}", tCode);
            Console.WriteLine("Date: {0}", date);
            Console.WriteLine("Amount: {0}", getAmount());
        }
    }


    class Program
    {

        static void Main(string[] args)
        {

/*
    "多态性"一词意味着具有多种形式

        在面向对象编程范式中
        多态性通常表示为"一个接口，多个函数"

        多态性可以是静态的，也可以是动态的
        在静态多态性中，对函数的响应在编译时确定
        在动态多态性中，响应在运行时确定

    静态多态性
        在编译时将函数链接到对象的机制称为早期绑定
        它也被称为静态绑定

    C# 提供了两种实现静态多态性的技术,它们是
        函数重载
        运算符重载
 */
/*
    函数重载
        在同一作用域内，可以对同一个函数名进行多个定义
        函数的定义必须在参数列表中的类型和/或参数数量上有所不同
        不能对仅返回类型不同的函数声明进行重载
 */
            Printdata p = new Printdata();

            // 调用 print 打印整数
            p.print(5);

            // 调用 print 打印浮点数
            p.print(500.263);

            // 调用 print 打印字符串
            p.print("Hello C++");

/*
    动态多态
        C# 允许创建抽象类，用于提供接口的部分类实现
        当派生类继承该类时，实现即完成
        抽象类包含抽象方法，这些方法由派生类实现
        派生类具有更专业的功能

        以下是关于抽象类的规则:
            不能创建抽象类的实例
            不能在抽象类之外声明抽象方法
            当一个类被声明为sealed时，它不能被继承
            抽象类不能被声明为sealed
 */
            Rectangle r = new Rectangle(10, 7);
            double a = r.area();
            Console.WriteLine("Area: {0}",a);

/*
    虚函数

    当你在一个类中定义了一个函数
    并希望在继承类中实现它时，可以使用虚函数

    这些虚函数在不同的继承类中可以有不同的实现
    并且这些函数的调用将在运行时决定

    语法：
        在父类中，使用 virtual 关键字来声明一个虚函数
        在子类中，使用 override 关键字来重写虚函数
 */
            Caller c = new Caller();
            Rectangle2 r2 = new Rectangle2(10, 7);
            Triangle t = new Triangle(10, 5);

            c.CallArea(r2);
            c.CallArea(t);

/*
    运算符重载

    您可以重新定义或重载 C# 中大多数内置运算符
    因此，程序员也可以使用用户定义类型的运算符

    重载运算符是具有特殊名称的函数
    名称由关键字 operator 加上所定义运算符的符号组成
    与其他函数类似，重载运算符具有返回类型和参数列表

 */
/*
    可重载和不可重载运算符

    下表描述了 C# 中运算符的重载能力
        序号	运算符 &说明
        1	    +、-、!、~、++、--
            这些一元运算符只接受一个操作数，并且可以重载。

        2	    +、-、*、/、%
            这些二元运算符只接受一个操作数，并且可以重载。

        3	    ==、!=、<、>、<=、>=
            比较运算符可以重载。

        4	    &&, ||
            条件逻辑运算符不能直接重载。

        5	    +=, -=, *=, /=, %=
            赋值运算符不能重载。

        6	    =, ., ?:, ->, new, is, sizeof, typeof
            这些运算符不能重载。
 */
            Box Box1 = new Box(); // 声明 Box1 类型为 Box
            Box Box2 = new Box(); // 声明 Box2 类型为 Box
            Box Box3 = new Box(); // 声明 Box3 类型为 Box
            Box Box4 = new Box();
            double volume = 0.0; // 在此处存储盒子的体积

            // Box1 的规格
            Box1.setLength(6.0);
            Box1.setBreadth(7.0);
            Box1.setHeight(5.0);

            // Box2 的规格
            Box2.setLength(12.0);
            Box2.setBreadth(13.0);
            Box2.setHeight(10.0);

            // 使用重载的 ToString() 显示盒子:
            Console.WriteLine("Box 1: {0}", Box1.ToString());
            Console.WriteLine("Box 2: {0}", Box2.ToString());

            // Box1 的体积
            volume = Box1.getVolume();
            Console.WriteLine("Volume of Box1: {0}",volume);

            // Box2 的体积
            volume = Box2.getVolume();
            Console.WriteLine("Volume of  Box2: {0}",volume);

            // 添加两个对象，如下所示:
            Box3 = Box1 + Box2;
            Console.WriteLine("Box3: {0}",Box3.ToString());

            // Box3 的体积
            volume = Box3.getVolume();
            Console.WriteLine("Volume of Box3 : {0}",volume);

            // 比较盒子
            if (Box1 > Box2)
                Console.WriteLine("Box1 is greater than Box2");
            else
                Console.WriteLine("Box1 is not greater than Box2");

            if (Box1 < Box2)
                Console.WriteLine("Box1 is less than Box2");
            else
                Console.WriteLine("Box1 is not less than Box2");

            if (Box1 >= Box2)
                Console.WriteLine("Box1 is greater or equal to Box2");
            else
                Console.WriteLine("Box1 is not greater or equal to Box2");

            if (Box1 <= Box2)
                Console.WriteLine("Box1 is less or equal to Box2");
            else
                Console.WriteLine("Box1 is not less or equal to Box2");

            if (Box1 != Box2)
                Console.WriteLine("Box1 is not equal to Box2");
            else
                Console.WriteLine("Box1 is not greater or equal to Box2");
            Box4 = Box3;

            if (Box3 == Box4)
                Console.WriteLine("Box3 is equal to Box4");
            else
                Console.WriteLine("Box3 is not equal to Box4");


/*
    接口

    接口被定义为一种语法契约，所有继承该接口的类都应遵循该契约
    接口定义了语法契约中"什么"部分
    而派生类定义了语法契约中"如何"部分

    接口定义属性、方法和事件，它们是接口的成员
    接口仅包含成员的声明，定义成员是派生类的责任
    这通常有助于提供派生类应遵循的标准结构

    抽象类在某种程度上也具有相同的用途
    但它们主要用于基类只需声明少量方法
    而派生类实现其功能的情况

    接口的特点：
        不能包含实现：
            接口中只能声明方法、属性、事件或索引器
            但不能提供具体的实现代码
        用于实现多重继承：
            C# 不支持类的多重继承，但可以通过接口实现多重继承
            类可以实现多个接口
        强制实现方法：
            实现接口的类必须实现接口中定义的所有成员（方法、属性等）
            否则会引发编译错误
        通过接口提供通用行为：
            接口用于提供一个通用的行为规范
            不同的类可以根据接口的定义提供具体的实现

    声明接口

        使用 interface 关键字声明接口
        它类似于类声明

        接口声明默认为 public

        以下是接口声明的示例
            public interface ITransactions {
                // 接口成员
                void showTransaction();
                double getAmount();
            }
 */
            Transaction t1 = new Transaction("001", "8/10/2012", 78900.00);
            Transaction t2 = new Transaction("002", "9/10/2012", 451900.00);

            t1.showTransaction();
            t2.showTransaction();


        }
    }
};


/*
 * 结构体
 * 枚举
 * 类
 * 继承
 */


namespace _07_OOP_数据处理
{
    // 定义结构体
    struct Books
    {
        private string title;
        private string author;
        private string subject;
        private int book_id;

        public void getValues(string t, string a, string s, int id)
        {
            title = t;
            author = a;
            subject = s;
            book_id = id;
        }

        public void display()
        {
            Console.WriteLine("Title : {0}", title);
            Console.WriteLine("Author : {0}", author);
            Console.WriteLine("Subject : {0}", subject);
            Console.WriteLine("Book_id :{0}", book_id);
        }
    }

    // 定义枚举
    enum Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

    // 定义类
    class Box {
        public double length; // 盒子的长度
        public double breadth; // 盒子的宽度
        public double height; // 盒子的高度

        // 构造函数
/*
    构造函数
        类构造函数是类的一个特殊成员函数
        每当我们创建该类的新对象时都会执行该函数

        构造函数的名称与类的名称完全相同
        并且没有任何返回类型

 */
        public void setLength( double len ) {
            length = len;
        }
        public void setBreadth( double bre ) {
            breadth = bre;
        }
        public void setHeight( double hei ) {
            height = hei;
        }
        public double getVolume() {
            return length * breadth * height;
        }
    }

    // 构析函数
    class Line
    {
        private double length; // Length of a line

        public Line()
        {
            // constructor
            Console.WriteLine("Object is being created");
        }

        ~Line()
        {
            //destructor
            Console.WriteLine("Object is being deleted");
        }

        public void setLength(double len)
        {
            length = len;
        }

        public double getLength()
        {
            return length;
        }
    }

    // 静态变量
    class StaticVar {
        public static int num;

        public void count() {
            num++;
        }
        public int getNum() {
            return num;
        }
    }

    // 基类
    class Shape {
        public void setWidth(int w) {
            width = w;
        }
        public void setHeight(int h) {
            height = h;
        }
        protected int width;
        protected int height;
    }

    // 派生类
    class Rectangle: Shape {
        public int getArea() {
            return (width * height);
        }
    }

    /*
        初始化基类
            派生类继承了基类的成员变量和成员方法
            因此，应该在创建子类之前创建超类对象
            您可以在成员初始化列表中指定超类的初始化方法
     */

    class Rectangle2 {

        //成员变量
        protected double length;
        protected double width;

        public Rectangle2(double l, double w) {
            length = l;
            width = w;
        }
        public double GetArea() {
            return length * width;
        }
        public void Display() {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }//end class Rectangle
    class Tabletop : Rectangle2 {
        private double cost;
        public Tabletop(double l, double w) : base(l, w) { }

        public double GetCost() {
            double cost;
            cost = GetArea() * 70;
            return cost;
        }
        public void Display() {
            base.Display();
            Console.WriteLine("Cost: {0}", GetCost());
        }
    }

    // 多重继承
    class Shape3 {
        public void SetWidth(int w) {
            width = w;
        }
        public void SetHeight(int h) {
            height = h;
        }
        protected int width;
        protected int height;
    }

    // 基类 PaintCost
    public interface PaintCost {
        int GetCost(int area);
    }

    // 派生类
    class Rectangle3 : Shape3, PaintCost {
        public int GetArea() {
            return (width * height);
        }
        public int GetCost(int area) {
            return area * 70;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {

/*
~   结构体
    >>  这是一种值类型数据类型
    >>  它可以帮助您使单个变量保存各种数据类型的相关数据
    >>  struct 关键字用于创建结构体

    特性：
        结构体可以包含方法、字段、索引器、属性、运算符方法和事件。

        结构体可以定义构造函数，但不能定义析构函数
        但是，您不能为结构体定义默认构造函数
        默认构造函数是自动定义的，无法更改

        与类不同，结构体不能继承其他结构体或类

        结构体不能用作其他结构体或类的基类

        一个结构体可以实现一个或多个接口

        结构体成员不能指定为抽象、虚拟或受保护

        使用 New 运算符创建结构体对象时
        系统会创建该对象并调用相应的构造函数
        与类不同，结构体无需使用 New 运算符即可实例化

        如果不使用 New 运算符，字段将保持未赋值状态
        并且对象只有在所有字段初始化完成后才能使用

 */

            Books book1 = new Books();   /* 将 Book1 声明为 Book 类型 */
            Books book2 = new Books();   /* 将 Book2 声明为 Book 类型 */

            /* book 1 规范 */
            book1.getValues("C Programming",
                "Nuha Ali", "C Programming Tutorial",6495407);

            /* book 2 规范 */
            book2.getValues("Telecom Billing",
                "Zara Ali", "Telecom Billing Tutorial", 6495700);

            /* 打印 Book1 信息 */
            book1.display();

            /* 打印 Book2 信息 */
            book2.display();


/*
~   枚举
    >>  枚举是一组命名的整数常量
    >>  枚举类型使用 enum 关键字声明

        C# 枚举是值数据类型
        换句话说，枚举包含其自身的值，并且不能继承或传递继承

    声明 enum 变量
        enum <enum_name> {
           enumeration list
        };

        enum_name 指定枚举类型名称
        枚举列表 是一个以逗号分隔的标识符列表


 */

            int weekdayStart = (int)Days.Mon;
            int weekdayEnd = (int)Days.Fri;

            Console.WriteLine("Monday: {0}", weekdayStart);
            Console.WriteLine("Friday: {0}", weekdayEnd);


/*
~   类
    >>  定义类时，实际上是为数据类型定义了一个蓝图
    >>  这实际上并不定义任何数据，但它定义了类名的含义
    >>  也就是说，类的对象由什么组成，以及可以对该对象执行哪些操作
    >>  对象是类的实例，构成类的方法和变量称为类的成员


    定义类
        <access specifier> class  class_name {
           // 成员变量
           <access specifier> <data type> variable1;
           <access specifier> <data type> variable2;
           ...
           <access specifier> <data type> variableN;
           // 成员方法
           <access specifier> <return type> method1(parameter_list) {
              // 方法主体
           }
           <access specifier> <return type> method2(parameter_list) {
              // 方法主体
           }
           ...
           <access specifier> <return type> methodN(parameter_list) {
              // 方法主体
           }
        }

    成员函数与封装
        类的成员函数是指在类定义中拥有其定义或其原型的函数
        类似于任何其他变量

        它对其所属类的任何对象进行操作
        并可以访问该对象的所有类成员

        成员变量是对象的属性(从设计角度来看)
        它们被保留为私有以实现封装
        这些变量只能使用公共成员函数访问

 */

            Box Box1 = new Box(); // 声明 Box 类型的 Box1
            Box Box2 = new Box(); // 声明 Box 类型的 Box2
            double volume = 0.0; // 在此处存储盒子的体积

            // 盒子 1 的规格
            Box1.height = 5.0;
            Box1.length = 6.0;
            Box1.breadth = 7.0;

            // 盒子 2 的规格
            Box2.height = 10.0;
            Box2.length = 12.0;
            Box2.breadth = 13.0;

            // 盒子 1 的体积
            volume = Box1.height * Box1.length * Box1.breadth;
            Console.WriteLine("Box1 的体积:{0}",volume);

            // 盒子 2 的体积
            volume = Box2.height * Box2.length * Box2.breadth;
            Console.WriteLine("Box2 的体积:{0}",volume);

            // 使用成员函数的封装来实现功能
            Box1.setLength(6.0);
            Box1.setBreadth(7.0);
            Box1.setHeight(5.0);

            // 盒子 2 的规格
            Box2.setLength(12.0);
            Box2.setBreadth(13.0);
            Box2.setHeight(10.0);

            // 盒子 1 的体积
            volume = Box1.getVolume();
            Console.WriteLine("Box1 的体积:{0}",volume);

            // 盒子 2 的体积
            volume = Box2.getVolume();
            Console.WriteLine("Box2 的体积:{0}",volume);

/*
    析构函数
        类的一个特殊成员函数
        每当类的对象超出作用域时都会执行
        析构函数的名称与类的名称完全相同
        但以波浪号 (~) 为前缀
        并且它既不返回值
        也不接受任何参数

        析构函数在退出程序之前释放内存资源非常有用
        析构函数不能被继承或重载
 */

            Line line = new Line();

            // set line length
            line.setLength(6.0);
            Console.WriteLine("Length of line : {0}", line.getLength());

/*
    类的静态成员
        我们可以使用 static 关键字将类成员定义为静态成员
        当我们将类的成员声明为静态成员时
        这意味着无论创建多少个类对象
        该静态成员都只有一个副本

        关键字 static 表示类中该成员只有一个实例
        静态变量用于定义常量
        因为它们的值可以通过调用类来获取
        而无需创建类的实例

        静态变量可以在成员函数或类定义之外初始化
        您也可以在类定义内部初始化静态变量

        还可以将成员函数声明为静态
        此类函数只能访问静态变量
        静态函数甚至在对象创建之前就已存在
 */

            StaticVar s1 = new StaticVar();
            StaticVar s2 = new StaticVar();

            s1.count();
            s1.count();
            s1.count();

            s2.count();
            s2.count();
            s2.count();

            Console.WriteLine("Variable num for s1: {0}", s1.getNum());
            Console.WriteLine("Variable num for s2: {0}", s2.getNum());

            StaticVar s = new StaticVar();

            s.count();
            s.count();
            s.count();

            Console.WriteLine("Variable num for s: {0}", s.getNum());


/*
    继承
        它允许我们根据另一个类来定义一个类
        这使得应用程序的创建和维护更加容易
        这也提供了重用代码功能并加快实现速度的机会

        创建类时，程序员可以指定新类继承现有类的成员
        而无需编写全新的数据成员和成员函数
        这个现有类称为基类，而新类称为派生类

        继承的思想实现了IS-A关系
        例如，哺乳动物是一种动物，狗是一种哺乳动物
        因此狗也是一种动物

 */

/*
    基类和派生类
        一个类可以从多个类或接口派生
        这意味着它可以从多个基类或接口继承数据和函数

    创建派生类的语法如下
        <acess-specifier> class <base_class> {
           ...
        }

        class <derived_class> : <base_class> {
           ...
        }
 */
            Rectangle rect = new Rectangle();

            rect.setWidth(5);
            rect.setHeight(7);

            // 打印对象的面积。
            Console.WriteLine("Total area: {0}",  rect.getArea());


            // 初始化基类
            Tabletop t = new Tabletop(4.5, 7.5);
            t.Display();

/*
    “多重继承”
        C# 不支持多重继承
        但是，可以使用接口来实现多重继承。
 */

            Rectangle3 rect3 = new Rectangle3();
            int area;

            rect3.SetWidth(5);
            rect3.SetHeight(7);
            area = rect3.GetArea();

            // 打印对象的面积。
            Console.WriteLine("Total area: {0}",  rect3.GetArea());
            Console.WriteLine("Total paint cost: ${0}" , rect3.GetCost(area));


        }
    }
}
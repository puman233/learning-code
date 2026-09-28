using System.Data;

namespace  _02_基础语法
{
    class Rectangle {

        // 成员变量
        double length;
        double width;

        public void Acceptdetails() {
            length = 4.5;
            width = 3.5;
        }
        public double GetArea() {
            return length * width;
        }
        public void Display() {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }
    class DataValue
        {
    /*
     数据类型
        整数类型(int、byte、long 等)
        浮点类型(float、double、decimal)
        字符类型 (char)
        布尔类型 (bool)
        枚举 (enum)
        结构体 (struct)

        整数：
            byte	1 字节	0 到 255
            sbyte	1 字节	-128 到 127
            short	2 字节	-32,768 到 32,767
            ushort	2 字节	0 到 65,535
            int	    4 字节	-2,147,483,648 到 2,147,483,647
            uint	4字节	0 到 4,294,967,295
            long	8 字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
            ulong	8 字节	0 到 18,446,744,073,709,551,615

        浮点型：
            float	4 字节	6-7 位小数
            double	8 字节	15-16 位小数
            decimal	16 字节	28-29 位小数
     */

        public int id = 1024;
        public long salary = 5000000L;
        public int Age = 30;
        public float disstance = 3200.45f;
        public decimal longBalance = 31423134.32m;

        // enum 是一种用于定义命名常量值的特殊数据类型。
        enum JobLevel
        {
            Intern,
            Junior,
            Mid,
            Senior,
            Manager
        };
        }

    // 结构体
    // 用于封装关联数据的值类型
    struct Employee
    {
        public int ID;
        public string Name;
        public string Address;
    }

    /*
        引用类型：
            引用类型不包含变量中存储的实际数据，而是包含对变量的引用。
            >>  它们指向一个内存位置

            使用多个变量时，引用类型可以指向一个内存位置
            如果其中一个变量更改了该内存位置中的数据，另一个变量的值也会自动反映更改

            内置引用类型示例：object、dynamic、string 和 array

        对象类型：
            对象类型是 C# 通用类型系统 (CTS) 中所有数据类型的最终基类

            对象类型可以被赋值为任何其他类型、值类型、引用类型、预定义或用户定义类型的值
            但是，在赋值之前，需要进行类型转换

        >>  当值类型转换为对象类型时，这被称为装箱

        >>  当对象类型转换为值类型时，这被称为拆箱
     */

    // 类变量
    class MathConstants
    {
        public const double Pi = 3.14159;
        public const int SpeedOfLight = 299792458;
    }

    class ExecuteRectangle {
        static void Main(string[] args) {
            unsafe      // 使用 unsafe 代码块包裹住，以使用指针
            {
                Rectangle rectangle = new Rectangle();
                rectangle.Acceptdetails();
                rectangle.Display();
                Console.WriteLine("面积：" + rectangle.GetArea());

                // 结构体
                Employee e = new Employee();
                e.ID = 1;
                e.Name = "John";
                // e.Address = new string('H', 10);    // Address:HHHHHHHHHH
                e.Address = "Shanghai";
                Console.WriteLine("id:" + e.ID);
                Console.WriteLine("Name:" + e.Name);
                Console.WriteLine("Address:" + e.Address);


                // 引用类型
                // 对象类型
                // 对象类型变量的类型检查在编译时进行
                // 拆箱
                object obj = 1001; // Student ID
                Console.WriteLine("Student ID: " + obj);

                obj = "Sudhir Sharma"; // Student Name
                Console.WriteLine("Student Name: " + obj);

                // 动态类型
                // 可以在动态数据类型变量中存储任何类型的值
                // 这些类型变量的类型检查在运行时进行
                // 语法为：dynamic <variable_name> = value;

                dynamic value = 10;
                Console.WriteLine("value:" + value);
                value = "Hello World";
                Console.WriteLine("Now value:" + value);

                // 字符串类型
                string firstName = "Sudhir";
                string lastName = "Sharma";
                string fullName = firstName + " " + lastName;

                Console.WriteLine("Full Name: " + fullName);

                // 数组类型
                string[] students = { "Zoya", "Yashna", "Olivia", "Naomi" };

                Console.WriteLine("Student List:");
                foreach (string student in students)
                {
                    Console.Write(student + "  ");
                }

                Console.WriteLine("\n");


                // 指针类型
                int grade = 90;
                int* ptr = &grade;

                Console.WriteLine("Original Grade: " + grade);
                Console.WriteLine("Memory Address: " + (ulong)ptr);

                *ptr = 95; // Modifying value using pointer
                Console.WriteLine("Updated Grade: " + grade);


/*
    类型转换

    隐式类型转换
    >>  隐式转换由 C# 编译器以类型安全的方式执行。
        例如，一个值可以从一种数据类型转换为另一种数据类型，
        而无需显式强制转换;
        可以从较小的整数类型转换为较大的整数类型;
        或者从派生类转换为基类。

    显式类型转换
    >>  显式转换由用户使用预定义函数显式完成。
        显式转换需要强制类型转换运算符。
 */
                int myInt = 9;

                // 自动转换:int 到 double
                double myDouble = myInt;

                Console.WriteLine(myInt);
                Console.WriteLine(myDouble);

                // 强制类型转换
                double d = 5673.74;
                int i;

                // 将 double 转换为 int。
                i = (int)d;
                Console.WriteLine(i);

                // 手动转换:int 到 float
                myInt = 10;
                float myFloat = (float) myInt;

                Console.WriteLine(myInt);
                Console.WriteLine(myFloat);

                // 使用Convert类进行类型转换
                string str1 = "123";
                int num1 = Convert.ToInt32(str1);
                char ch1 = Convert.ToChar(str1[1]); //2

                Console.WriteLine(num1);
                Console.WriteLine(ch1);

                // 使用 Parse() 方法进行类型转换
                // 将数字的字符串表示形式转换为其相应的数据类型
                string str2 = "456";
                int num2 = int.Parse(str2);
                Console.WriteLine(num2);

                // 使用 TryParse() 方法进行类型转换
                // 安全地将字符串转换为数字数据类型，
                // 并返回指示成功或失败的布尔值。
                string str3 = "789";
                if (int.TryParse(str3, out int result)) {
                    Console.WriteLine(result);
                } else {
                    Console.WriteLine("Conversion failed.");
                }

    /*
        85 		/* 十进制 * /
        0x4b 	/* 十六进制 * /
        30 		/* 整数 * /
        30u 	/* 无符号整数 * /
        30l 	/* 长整型 * /
        30ul 	/* 无符号长整型 * /

        3.14159 		/* 合法 * /
        314159E-5F 		/* 合法 * /
        510E 			/* 非法:指数不完整 * /
        210f 			/* 非法:无小数或指数 * /
        .e55 			/* 非法:缺少整数或分数 * /

    字符串字面量或常量用双引号 "" 或 @"" 括起来
        "hello, dear"
        "hello, \
        dear"
        "hello, " "d" "ear"
        @"hello dear"

     */

                // 定义常量
                const int AGE = 18;

                // 类常量
                // 类常量在类内部使用 const 关键字声明
                // 它们是隐式静态的，这意味着它们属于类而不是实例
                Console.WriteLine("Value of Pi: " + MathConstants.Pi);
                Console.WriteLine("Speed of Light: " + MathConstants.SpeedOfLight);

                const double pi = 3.14159;

                // 常量声明
                double r;
                Console.WriteLine("Enter Radius: ");
                r = Convert.ToDouble(Console.ReadLine());

                double areaCircle = pi * r * r;
                Console.WriteLine("Radius: {0}, Area: {1}", r, areaCircle);

                // 字符串文字
                string regularString = "Hello, World!";
                string verbatimString = @"C:\Users\Admin\Documents\";

                Console.WriteLine("Regular String Literal: " + regularString);
                Console.WriteLine("Verbatim String Literal: " + verbatimString);

                // 浮点文字
                float floatLiteral = 3.14F;
                // 默认浮点类型
                double doubleLiteral = 3.14159265359;
                // 需要"M"后缀以实现高精度
                decimal decimalLiteral = 3.14159265359M;

                Console.WriteLine("Floating Point Literals:");
                Console.WriteLine("Float Literal: " + floatLiteral);
                Console.WriteLine("Double Literal: " + doubleLiteral);
                Console.WriteLine("Decimal Literal: " + decimalLiteral);

            }
        }
    }
}

// using 关键字用于在程序中包含 System 命名空间。
// 一个程序通常包含多个 using 语句。
// using 语句导入命名空间，允许访问内置类和方法。

/*
每个程序都以 using 语句开头，这些语句用于包含必要的命名空间。
namespace(命名空间) 将相关的类组合在一起。
class(类) 包含程序逻辑。
Main() 方法是程序的入口点，程序从这里开始执行。
Main() 中的语句按顺序执行。
*/

// namespace 是类的集合
namespace _01_程序结构
{
    class People
    {
        public int Age = 18;
        public string Name = "Elysia";

        public void Display()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Age: " + Age);
        }

    }

    class HelloWorld
    {   // class 声明
        // 类通常包含多个方法。方法定义了类的行为。
        static void Main(string[] args)
        {
            /* 我的第一个 C# 程序 */
            Console.WriteLine("Hello World");
            //  Console.ReadKey();
            // 适用于 VS.NET 用户。这会使程序等待按键，并防止从 Visual Studio .NET 启动程序时屏幕快速运行和关闭。

            People myGirl = new People();
            Console.WriteLine("Her name: " + myGirl.Name);

            myGirl.Display();

        }
    }



}
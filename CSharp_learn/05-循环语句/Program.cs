using System;
using System.IO;

namespace _05_循环语句
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] number = { 1, 2, 3, 5, 6 };
            int i, n, j;
            int a = 0, b = 1, c;

            for (i = 0; i < number.Length; i++) {
                Console.Write(number[i] + " ");
            }
            Console.WriteLine();

            for (i = 0; i < number.LongLength; i++)
            {
                Console.Write(number[i] + " ");
            }
            Console.WriteLine();

            /* for 循环执行 */
            for (a = 10; a < 20; a = a + 1) {
                Console.WriteLine("value of a: {0}", a);
            }

            // 斐波那契数列
            n = 10;
            a = b = 1;
            Console.Write("{0} {1} ", a , b);
            for (i = 2; i < n; i++)
            {
                c = a + b;
                Console.Write(c + " ");
                a = b;
                b = c;
            }
            Console.WriteLine();

            //使用 while 循环打印从 1 到 5 的数字
            i = 1;
            while (i <= 5)
            {
                Console.Write("Number: " + i + " ");
                i++;
            }
            Console.WriteLine();

            // 使用 do-while 循环打印从 1 到 5 的数字
            i = 1;
            do
            {
                Console.Write("Number: " + i + " ");
                i++;
            } while (i <= 5);

            // 1. 读取用户输入，直到满足条件
            // while 循环可用于持续接受用户输入，直到他们输入特定值。

            string? input;  // 加了个 ? 允许 input 为 null
            while (true) {
                Console.Write("Enter a word (type 'exit' to stop): ");
                input = Console.ReadLine();
                if (input == "exit")
                    break;
                Console.WriteLine("You entered: " + input);
            }

            // 2. 循环直至输入有效信息
            // while 循环确保用户输入正确后再继续执行。

            int Number;
            Console.Write("Enter a positive number: ");
            while (!int.TryParse(Console.ReadLine(), out Number) || Number <= 0) {
                Console.Write("Invalid input! Please enter a positive number: ");
            }
            Console.WriteLine("You entered: " + number);

            // 3. 处理文件直至到达末尾
            // while 循环适用于逐行读取文件，直至没有更多可用数据。

            string? filePath = "sample.txt";    // 这是合法的，filePath 可以是 null
            if (File.Exists(filePath)) {
                using (StreamReader reader = new StreamReader(filePath)) {
                    string line;
                    while ((line = reader.ReadLine()) != null) {
                        Console.WriteLine(line);
                    }
                }
            }

            // 4. 生成随机数直至满足条件
            // 此 while 循环在动态检查条件的游戏或模拟中非常有用。

            Random rand = new Random();
            int num;
            do {
                num = rand.Next(1, 10);
                Console.WriteLine("Generated: " + num);
            } while (num != 7);
            Console.WriteLine("Stopped at 7!");

            // 5. 运行后台任务直至满足停止条件
            // while 循环可用于持续检查系统状态或等待标志位发生变化。

            bool isRunning = true;
            int counter = 0;
            while (isRunning) {
                Console.WriteLine("Running... " + counter);
                Thread.Sleep(1000); // 模拟延迟
                counter++;
                if (counter == 5) isRunning = false;
            }
            Console.WriteLine("Process stopped.");


            // 嵌套for循环找素数
            for (i = 2; i < 100; i++) {
                for (j = 2; j <= (i / j); j++)
                    if ((i % j) == 0) break; // 如果找到因子，则不是素数
                if (j > (i / j)) Console.WriteLine("{0} is prime", i);
            }
            




        }
    }
}
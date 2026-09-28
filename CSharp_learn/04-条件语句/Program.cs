using System;

namespace _04_条件语句
{
    class Program
    {
        static void Main(string[] args)
        {
            // 定义局部变量
            int temperature = 21;

            // 使用 if 语句检查条件
            if (temperature > 25)
            {
                Console.WriteLine("It's a hot day.");
            }
            else
            {
                Console.WriteLine("The weather is pleasant.");
            }

            Console.WriteLine($"Current temperature: {temperature} degree C");

/*
    switch(expression) {
       case constant-expression1  :
          statement(s);
          break;
       case constant-expression2  :
       case constant-expression3  :
          statement(s);
          break;

       /* 你可以有任意数量的 case 语句 * /
       default : /* 可选 * /
       statement(s);

    嵌套switch规则
        每个 switch 中的表达式必须是整数类型(例如，int、char)或枚举类型。
        每个 switch 可以包含多个 case 标签，并且 case 值必须与 switch 表达式的数据类型匹配。
        case 值必须是常量或字面量(例如，数字或字符)。 不允许使用变量作为 case 的值。
        当 case 匹配时，该 case 中的代码将一直运行，直到遇到 break 语句。
        每个 case 都必须以 break 语句 结束，以停止执行。缺少 break 将导致 编译时错误。
        switch 语句可以嵌套，这意味着一个 switch 语句可以放在 case 块中的另一个 switch 语句内。
        外部 switch 语句和内部 switch 语句都可以包含一个 default case，当没有其他 case 匹配时运行该 case。
}
 */
            /* 局部变量定义 */
            char grade = 'B';

            switch (grade) {
                case 'A':
                    Console.WriteLine("Excellent!");
                    break;
                case 'B':
                case 'C':
                    Console.WriteLine("Well done");
                    break;
                case 'D':
                    Console.WriteLine("You passed");
                    break;
                case 'F':
                    Console.WriteLine("Better try again");
                    break;
                default:
                    Console.WriteLine("Invalid grade");
                    break;
            }
            Console.WriteLine("Your grade is  {0}", grade);

            // 示例:用于选择部门和角色的嵌套 Switch 语句
            // Define department
            string department = "IT";

            // Define Role
            string role = "Manager";

            switch (department) {
                case "IT":
                    switch (role) {
                        case "Developer":
                            Console.WriteLine("IT - Developer: Responsible for coding.");
                            break;
                        case "Tester":
                            Console.WriteLine("IT - Tester: Ensures software quality.");
                            break;
                        case "Manager":
                            Console.WriteLine("IT - Manager: Oversees IT projects.");
                            break;
                        default:
                            Console.WriteLine("Invalid IT Role!");
                            break;
                    }
                    break;

                case "HR":
                    switch (role) {
                        case "Recruiter":
                            Console.WriteLine("HR - Recruiter: Manages hiring.");
                            break;
                        case "Trainer":
                            Console.WriteLine("HR - Trainer: Conducts training sessions.");
                            break;
                        case "Coordinator":
                            Console.WriteLine("HR - Coordinator: Handles HR operations.");
                            break;
                        default:
                            Console.WriteLine("Invalid HR Role!");
                            break;
                    }
                    break;

                case "Finance":
                    switch (role) {
                        case "Accountant":
                            Console.WriteLine("Finance - Accountant: Manages financial records.");
                            break;
                        case "Auditor":
                            Console.WriteLine("Finance - Auditor: Conducts financial audits.");
                            break;
                        case "Analyst":
                            Console.WriteLine("Finance - Analyst: Analyzes financial data.");
                            break;
                        default:
                            Console.WriteLine("Invalid Finance Role!");
                            break;
                    }
                    break;

                default:
                    Console.WriteLine("Invalid Department!");
                    break;
            }


        }
    }
}
/*
 * 命名空间
 * using 关键字
 * 预处理
 */

/*
 * 预处理器指令
    预处理器指令指示编译器在实际编译开始之前预处理信息

    所有预处理器指令都以 # 开头
    并且一行中预处理器指令前只能出现空格
    预处理器指令不是语句，因此它们不以分号 (;) 结尾

    C# 编译器没有单独的预处理器
    但是，这些指令的处理方式与存在预处理器的情况相同
    在 C# 中，预处理器指令用于辅助条件编译
    与 C 和 C++ 指令不同，它们不用于创建宏
    预处理器指令必须是一行中唯一的指令
 */
/*
 * C# 中的预处理器指令
    下表列出了 C# 中可用的预处理器指令

    序号	预处理器指令及说明
    1	    #define
            它定义了一个字符序列，称为符号。

    2	     #undef
            它允许您取消定义一个符号。

    3	    #if
            它允许测试一个或多个符号，看它们是否为真。
            以 #if 指令开头的条件指令必须明确以 #endif 指令结尾

    4	    #else
            它允许与#if一起使用，创建复合条件指令。

    5	    #elif
            允许创建复合条件指令。

    6	    #endif
            指定条件指令的结尾。

    7       #line
            允许修改编译器的行号以及(可选)错误和警告输出的文件名。

    8       #error
            允许从程序中的特定位置生成错误代码。

    9       #warning
            它允许在代码中的特定位置生成一级警告。

    10      #region
            它允许您指定一个代码块
            您可以在使用 Visual Studio 代码编辑器的大纲功能时展开或折叠该代码块。

    11      #endregion
            它标记 #region 块的结束。
 */
/*
 * #define 预处理器
    #define 预处理器指令创建符号常量。

    #define 允许您定义一个符号
    通过将该符号用作传递给 #if 指令的表达式
    该表达式的计算结果为 true

    语法如下：
        #define symbol
 */
#define PI
#define DEBUG
#define VC_V10


/*
 * using 关键字
    using 关键字表明程序正在使用给定命名空间中的名称

    例如，我们在程序中使用 System 命名空间
    Console 类就定义在那里

    我们只需这样写:
        Console.WriteLine ("Hello there");

    我们可以将完全限定名称写为:
        System.Console.WriteLine("Hello there");

    您还可以使用 using namespace 指令避免在名称空间前添加前缀
    该指令告诉编译器后续代码正在使用指定命名空间中的名称
 */

// 使用using重写
using third_space;
using fourth_space;
// 嵌套
using fifth_space;
using fifth_space.sixth_space;

using System.Text.RegularExpressions;

namespace third_space
{
    class abc
    {
        public void func()
        {
            Console.WriteLine("Inside third_space");
        }
    }
}
namespace  fourth_space {
    class efg {
        public void func() {
            Console.WriteLine("Inside fourth_space");
        }
    }
}

/*
 * namespace(命名空间)旨在提供一种方法来区分不同的名称
 * 在一个命名空间中声明的类名不会与在另一个命名空间中声明的相同类名冲突
 */
namespace first_space {
    class namespace_cl {
        public void func() {
            Console.WriteLine("Inside first_space");
        }
    }
}
namespace second_space {
    class namespace_cl {
        public void func() {
            Console.WriteLine("Inside second_space");
        }
    }
}

/*
 * 嵌套命名空间

    您可以在一个命名空间内定义另一个命名空间，如下所示

    namespace namespace_name1 {

        // 代码声明
        namespace namespace_name2 {
            // 代码声明
        }
    }
 */

namespace fifth_space
{
    class hij {
        public void func() {
            Console.WriteLine("Inside fifth_space");
        }
    }
    namespace sixth_space {
        class lmn {
            public void func() {
                Console.WriteLine("Inside sixth_space");
            }
        }
    }
}


namespace _09_OOP_数据处理
{
    class Program
    {
        // 匹配
        private static void showMatch(string text, string expr) {
            Console.WriteLine("The Expression: " + expr);
            MatchCollection mc = Regex.Matches(text, expr);

            foreach (Match m in mc) {
                Console.WriteLine(m);
            }
        }


        static void Main(string[] args)
        {
            // 调用命名空间的类函数
            first_space.namespace_cl fc = new first_space.namespace_cl();
            second_space.namespace_cl sc = new second_space.namespace_cl();

            fc.func();
            sc.func();

            // 使用using重写后
            abc abc = new abc();
            efg efg = new efg();

            abc.func();
            efg.func();

            // 嵌套using
            hij hij = new hij();
            lmn lmn = new lmn();

            hij.func();
            lmn.func();


            // 预处理器指令
            // define指令
/*
 * 条件指令
    您可以使用 #if 指令创建条件指令
    条件指令可用于测试一个或多个符号
    检查它们的计算结果是否为真

    如果计算结果为真
    编译器将执行 #if 和下一个指令之间的所有代码

    条件指令的语法为
        #if symbol [operator symbol]...

        其中，symbol 是要测试的符号的名称
        您也可以使用 true 和 false
        或在符号前面添加否定运算符

        operator symbol 是用于计算符号的运算符
        运算符可以是以下任一种:
            ==(相等)
            !=(不等)
            &&(与)
            ||(或)
*/
#if (PI)
            Console.WriteLine("PI is defined");
#else
                Console.WriteLine("PI is not defined");
#endif

#if (DEBUG && !VC_V10)
         Console.WriteLine("DEBUG is defined");
#elif (!DEBUG && VC_V10)
         Console.WriteLine("VC_V10 is defined");
#elif (DEBUG && VC_V10)
            Console.WriteLine("DEBUG and VC_V10 are defined");
#else
         Console.WriteLine("DEBUG and VC_V10 are not defined");
#endif

/*
 * 正则表达式
    正则表达式是一种可以与输入文本匹配的模式
    .Net 框架提供了一个正则表达式引擎来实现这种匹配
    一个模式由一个或多个字符文字、运算符或构造函数组成

    Regex 类

    Sr.No.	方法 &说明
    1	public bool IsMatch(string input)
        指示 Regex 构造函数中指定的正则表达式是否在指定的输入字符串中找到匹配项。

    2	public bool IsMatch(string input, int startat)
        指示 Regex 构造函数中指定的正则表达式是否在指定的输入字符串中找到匹配项
        该匹配项从字符串中指定的起始位置开始。

    3	public static bool IsMatch(string input, string pattern)
        指示指定的正则表达式是否在指定的输入字符串。

    4	public MatchCollection Matches(string input)
        在指定的输入字符串中搜索所有出现的正则表达式。

    5	public string Replace(string input, string replacement)
        在指定的输入字符串中，将所有与正则表达式模式匹配的字符串替换为指定的替换字符串。

    6	public string[] Split(string input)
        将输入字符串拆分为一个子字符串数组
        拆分位置由正则表达式中指定的正则表达式模式定义
        构造函数


    基本语法：
    1. 字符匹配：
        a：匹配字符 a。
        [abc]：匹配字符 a、b 或 c 中的任意一个字符。
        [^abc]：匹配除了 a、b 和 c 以外的任何字符（取反）。

    2. 预定义字符集：
        \d：匹配任何数字字符，等价于 [0-9]。
        \D：匹配任何非数字字符，等价于 [^0-9]。
        \w：匹配字母、数字和下划线（等价于 [a-zA-Z0-9_]）。
        \W：匹配任何非字母、数字和下划线的字符。
        \s：匹配任何空白字符（如空格、制表符、换行符等）。
        \S：匹配任何非空白字符。

    3. 数量词：
        *：匹配前面的元素零次或多次。
        +：匹配前面的元素一次或多次。
        ?：匹配前面的元素零次或一次。
        {n}：匹配前面的元素恰好 n 次。
        {n,}：匹配前面的元素至少 n 次。
        {n,m}：匹配前面的元素最少 n 次，最多 m 次。

    4. 边界匹配：
        ^：匹配字符串的开始。
        $：匹配字符串的结尾。
        \b：匹配单词的边界（例如空格、标点符号）。
        \B：匹配非单词边界。

    5. 分组和捕获：
        (abc)：分组，匹配字符串 "abc"。分组可以用来提取匹配的子字符串。
        (?:abc)：非捕获分组，仅用于分组但不捕获匹配的字符串。
        \1, \2, …：反向引用，引用匹配的分组（例如，\1 表示第一个捕获组的内容）。

    6. 或匹配：
        a|b：匹配 a 或 b。

    7. 转义字符：
        \：用于转义字符，允许你匹配特殊字符（如 .、*、? 等）
            或者匹配控制字符（如 \n 表示换行符）。
 */

            // 匹配以"S"开头的单词
            string str1 = "A Thousand Splendid Suns";

            Console.WriteLine("Matching words that start with 'S': ");
            showMatch(str1, @"\bS\S*");

            // 匹配以"m"开头、以"e"结尾的单词
            string str2 = "make maze and manage to measure it";

            Console.WriteLine("Matching words start with 'm' and ends with 'e':");
            showMatch(str2, @"\bm\S*e\b");

        }
    }
};


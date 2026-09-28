using System;

namespace _03_运算符
{
    class Program
    {
        static void Main()
        {
/*
    算数运算符
        +	将两个操作数相加	A + B = 30
        -	从第一个操作数中减去第二个操作数	A - B = -10
        *	将两个操作数相乘	A * B = 200
        /	将分子除以分母	B / A = 2
        %	模运算符，求整数除法后的余数	B % A = 0
        ++	增量运算符将整数值加一	A++ = 11
        --	减量运算符将整数值减一	A-- = 9


    关系运算符
        ==	检查两个操作数的值是否相等，如果相等，则条件成立。	(A == B) 不成立。
        !=	检查两个操作数的值是否相等，如果值不相等，则条件成立。	(A != B) 为真。
        >	检查左操作数的值是否大于右操作数的值，如果是，则条件成立。	(A > B) 不为真。
        <	检查左操作数的值是否小于右操作数的值，如果是，则条件成立。	(A < B) 为真。
        >=	检查左操作数的值是否大于或等于右操作数的值，如果是，则条件成立。	(A >= B) 不为真。
        <=	检查左操作数的值是否小于或等于右操作数的值，如果是，则条件成立。	(A <= B) 为真。

    逻辑运算符
        &&	称为逻辑与运算符。如果两个操作数都非零，则条件为真。	(A && B) 为假。
        ||	称为逻辑或运算符。如果两个操作数中有一个非零，则条件为真。	(A || B) 为真。
        !	称为逻辑非运算符。用于反转其操作数的逻辑状态。如果条件为真，则逻辑非运算符将返回假。	!(A && B) 为真。

    赋值运算符
        =	简单赋值运算符，将右侧操作数的值赋给左侧操作数	C = A + B 将 A + B 的值赋给 C
        +=	加法与赋值运算符，它将右操作数与左操作数相加，并将结果赋给左操作数	C += A 等同于 C = C + A
        -=	减法与赋值运算符，它将左操作数减去右操作数，并将结果赋给左操作数	C -= A 等同于 C = C - A
        *=	乘法与赋值运算符，它将右操作数相乘与左操作数相除，并将结果赋值给左操作数	C *= A 等同于 C = C * A
        /=	除法与赋值运算符，它将左操作数与右操作数相除，并将结果赋值给左操作数	C /= A 等同于 C = C / A
        %=	模与赋值运算符，它将两个操作数相除，并将结果赋值给左操作数	C %= A 等同于 C = C % A
        <<=	左移与赋值运算符	C <<= 2 与 C = C << 2 相同
        >>=	右移与赋值运算符	C >>= 2 与 C = C >> 2 相同
        &=	按位与赋值运算符	C &= 2 与 C = C & 2 相同
        ^=	按位异或赋值运算符	C ^= 2 与 C = C ^ 2 相同
        |=	按位异或赋值运算符	C |= 2 与 C = C | 2 相同

    三元运算符
        C# 三元运算符需要三个操作数并执行条件检查;
        它是 if-else 语句的快捷方式。

    杂项运算符
        C# 杂项运算符是不属于算术、逻辑、关系或位运算类别的特殊运算符。
        这些运算符主要用于类型检查、空值处理和内存引用。

        sizeof()	返回数据类型的大小。	sizeof(int)，返回 4。
        typeof()	返回类的类型。	typeof(StreamReader);
        &	返回变量的地址。	&a; 返回变量的实际地址。
        *	指向变量的指针。	*a; 创建指向变量的名为"a"的指针。
        ? :	条件表达式	如果条件为真?则值为 X :否则值为 Y
        is	判断对象是否属于特定类型。	If( Ford is Car) // 检查 Ford 是否为 Car 类的对象。
        as	如果转换失败，则进行类型转换，不抛出异常。	Object obj = new StringReader("Hello");
        StringReader r = obj as StringReader;

    运算符优先级
    >>  优先级由高到低排序：
        后缀	    () [] -> . ++ - -	从左到右
        一元运算符	+ - ! ~ ++ - - (type)* & sizeof	从右到左
        乘法	    * / %	从左到右
        加法	    + -	从左到右
        移位	    << >>	从左到右
        关系	    < <= > >=	从左到右
        相等	    == !=	从左到右
        按位与	    &	从左到右
        按位异或	^	从左到右
        按位或	    |	从左到右
        逻辑与	    &&	从左到右
        逻辑或	    ||	从左到右
        条件	    ?:	从右到左
        赋值	    = += -= *= /= %=>>= <<= &= ^= |=	从右到左
        逗号	    ,	从左到右

    位运算符
        位运算符允许进行二进制级别的运算。
        主要用于性能优化、底层编程、加密、网络和系统编程。

        位运算符操作数字的各位
        通常用于高效计算、标志位运算和硬件交互

        >> 假设变量 A 为 60，变量 B 为 13
            &	如果二进制"与"运算符在两个操作数中都存在，则将一位复制到结果中。	(A & B) = 12，即 0000 1100
            |	如果二进制"或"运算符在任意一个操作数中都存在，则将一位复制到结果中。操作数。	(A | B) = 61，即 0011 1101
            ^	二进制异或运算符复制一个操作数中设置了位的位，但两个操作数均设置了位。	(A ^ B) = 49，即 0011 0001
            ~	二进制一补码运算符是一元运算符，具有"翻转"位的效果。	(~A ) = -61，由于它是一个有符号二进制数，因此在二进制补码中为 1100 0011。
            <<	二进制左移运算符。左侧操作数的值按右侧操作数指定的位数向左移动。	A << 2 = 240，即 1111 0000
            >>	二进制右移运算符。左侧操作数的值按右侧操作数指定的位数向右移动。	A >> 2 = 15，即 0000 1111

*/
            int n1 = 10, n2 = 4;
            Console.WriteLine("Addition: " + (n1 + n2));
            Console.WriteLine("Multiplication: " + (n1 * n2));
            Console.WriteLine("Modulo: " + (n1 % n2));


            int a = 20, b = 15;
            Console.WriteLine("Is a > b? " + (a > b));
            Console.WriteLine("Is a == b? " + (a == b));

            bool x = true, y = false;
            Console.WriteLine("AND (&&) : " + (x && y));
            Console.WriteLine("OR (||)  : " + (x || y));
            Console.WriteLine("NOT (!)  : " + (!x));

            // 位运算符
            a = 5;
            b = 3;  // Binary: a = 0101, b = 0011
            // 位与运算仅当两个操作数在该位置都为 1 时，才会将每个位设置为 1。
            int result = a & b; // 0101 & 0011 = 0001 (1)
            Console.WriteLine("Bitwise AND: " + result);

            // 按位或运算中，若任一操作数为 1，则将每位设置为 1
            result = a | b; // 0101 | 0011 = 0111 (7)
            Console.WriteLine("Bitwise OR: " + result);

            // 按位异或运算会将相应位设置为 1(如果相应位不同)
            result = a ^ b; // 0101 ^ 0011 = 0110 (6)
            Console.WriteLine("Bitwise XOR: " + result);

            // 按位非会取反每个位(将 1 变为 0，反之亦然)
            result = ~a;   // NOT 00000101 = 11111010 (Twos Complement)
            Console.WriteLine("Bitwise NOT: " + result);

            // 左移 (<<) 将位向左移动，使数字乘以 2^n
            result = a << 2;
            Console.WriteLine("Left Shift: " + result);

            result = a << 3;
            Console.WriteLine("Left Shift: " + result);

            // 右移 (>>) 将位向右移动，将数字除以 2^n
            result = a >> 2;
            Console.WriteLine("Right Shift: " + result);

            result = a >> 3;
            Console.WriteLine("Right Shift: " + result);

            // 示例4：检查数字是偶数还是奇数
            int number = 10;

            if ((number & 1) == 0)
                Console.WriteLine("Even");
            else
                Console.WriteLine("Odd");

            // 不使用临时变量交换两个数字
/*
    >>  第一步：a = a ^ b;
假设 a = 5（即 0101），b = 10（即 1010）。
a = a ^ b 后，a 的值变为 0101 ^ 1010 = 1111，即 a = 15。
    >>  第二步：b = a ^ b;
此时，a = 15（即 1111），b = 10（即 1010）。
b = a ^ b 后，b = 1111 ^ 1010 = 0101，即 b = 5（原来的 a 值）。
    >>  第三步：a = a ^ b;
此时，a = 15（即 1111），b = 5（即 0101）。
a = a ^ b 后，a = 1111 ^ 0101 = 1010，即 a = 10（原来的 b 值）。
 */
            a = 5;
            b = 10;

            a = a ^ b;
            b = a ^ b;
            a = a ^ b;

            Console.WriteLine("After Swap: a = " + a + ", b = " + b);


            // 杂项运算符
            // 空值合并运算符（??）
            // 在处理具有空值的变量时非常有用。
            // 如果变量为空，此运算符会直接赋值默认值
            int? number2 = null;
            int result2 = number2 ?? 100; // 如果"number"为空，则赋值为 100
            Console.WriteLine(result2);

            // 空合并赋值 (??=)
            // ??= 运算符仅当变量为空时才赋值
            string message = null;
            message ??= "Default Message"; // 仅当消息为空时才分配值
            Console.WriteLine(message);

            // 类型检查运算符 (is)
            // is 运算符检查对象是否属于特定类型
            object obj = "Hello, World!";

            if (obj is string)
            {
                Console.WriteLine("obj is a string.");
            }

            // 安全类型转换 (as)
            // 可以安全地执行类型转换，且不会引发异常
            object obj2 = "Hello, C#";
            string str2 = obj2 as string;

            if (str2 != null)
            {
                Console.WriteLine("Safe casting successful: " + str2);
            }

            // 示例 7:在 Web 表单中使用 ?? 作为默认值
            string userInput = null;
            string finalInput = userInput ?? "Default Username";

            Console.WriteLine("User: " + finalInput);

            // 示例 8:使用 is 检查对象类型
            object obj3 = 42;

            if (obj3 is int number3)
            {
                Console.WriteLine("obj is an integer: " + number3);
            }


        }
    }
}


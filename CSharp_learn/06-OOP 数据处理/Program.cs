/*
 * 方法
 * 封装
 * 可空值类型
 * 数组
 * 字符串
 */

namespace  _06_OOP_数据处理
{
/*
 * 方法
 */
	class Rectangle {
		// 私有访问说明符
		// 允许类向其他函数和对象隐藏其成员变量和成员函数
		// 只有同一类的函数才能访问其私有成员
		//成员变量
		private double length;
		private double width;

		// 内部访问说明符
		// 允许类将其成员变量和成员函数暴露给当前程序集中的其他函数和对象
		// 换句话说，任何带有内部访问说明符的成员都可以从定义该成员的应用程序中的任何类或方法访问
		internal void Acceptdetails() {
			Console.WriteLine("Enter Length: ");
			length = Convert.ToDouble(Console.ReadLine());
			Console.WriteLine("Enter Width: ");
			width = Convert.ToDouble(Console.ReadLine());
		}

		double GetArea() {
			return length * width;
		}
		// 公共访问说明符
		// 允许类将其成员变量和成员函数暴露给其他函数和对象
		// 任何公共成员都可以从类外部访问
		public void Display() {
			Console.WriteLine("Length: {0}", length);
			Console.WriteLine("Width: {0}", width);
			Console.WriteLine("Area: {0}", GetArea());
		}
	}//end class Rectangle


	// 定义方法
	class NumberManipulator {
		// 找大值
		public int FindMax(int num1, int num2) {
			/*局部变量声明*/
			int result;

			if (num1 > num2)
				result = num1;
			else
				result = num2;

			return result;
		}

		// 递归 算阶乘
		public int Factorial(int num) {
			/*局部变量声明*/
			int result;
			if (num == 1) {
				return 1;
			} else {
				result = Factorial(num - 1) * num;
				return result;
			}
		}
	}


	class Program
	{
		static void Main(string[] args)
		{
			int i, j;

/*
~	封装
	>>	"将一个或多个对象封装在物理或逻辑包中的过程"
	>>	在面向对象编程方法中，封装阻止访问实现细节

	>>	抽象和封装是面向对象编程中的相关特性
	>>	抽象允许将相关信息可视化
	>>	而封装使程序员能够实现所需的抽象级别。

	>>	封装是通过使用访问说明符来实现的
	>>	访问说明符定义了类成员的范围和可见性

		C# 支持以下访问说明符
			Public
			Private
			Protected
			Internal
			Protected internal

		受保护访问说明符	Protected
			允许子类访问其基类的成员变量和成员函数
			这有助于实现继承

		受保护的内部访问说明符	Protected internal
			受保护的内部访问说明符允许类将其成员变量和成员函数隐藏
			使其对其他类对象和函数(同一应用程序中的子类除外)不可见
			这也适用于实现继承
 */
			// 公共访问说明符
			Rectangle r = new Rectangle();
			r.Acceptdetails();
			r.Display();



/*
~	方法
	>>	方法是一组共同执行一项任务的语句
	>>	每个 C# 程序至少有一个包含名为 Main 的方法的类

	定义方法
	>>	定义方法时，基本上就是声明其结构的元素
	>>	在 C# 中定义方法的语法如下:-

	<Access Specifier> <Return Type> <Method Name>(Parameter List)
		{
		   Method Body
		}

	访问说明符 - 这决定了变量或方法对其他类的可见性
	返回类型 - 方法可以返回一个值
				返回类型是方法返回值的数据类型。如果方法不返回任何值，则返回类型为void。
	方法名称 - 方法名称是唯一标识符，并且区分大小写
				它不能与类中声明的任何其他标识符相同
	参数列表 - 参数括在括号中，用于传递和接收方法中的数据
				参数列表指的是方法参数的类型、顺序和数量
				参数是可选的;也就是说，方法可以不包含任何参数
	方法主体 − 包含完成所需操作所需的一组指令
 */

			// 调用方法
			/* 局部变量定义 */
			int a = 100;
			int b = 200;
			int ret;
			NumberManipulator n = new NumberManipulator();

			//调用 FindMax 方法
			ret = n.FindMax(a, b);
			Console.WriteLine("Max value is : {0}", ret );

			// 调用 Factorial 方法
			Console.WriteLine("Factorial of 7 is : {0}", n.Factorial(7));
			Console.WriteLine("Factorial of 8 is : {0}", n.Factorial(8));



/*
~	可空值	类型
	>>	您可以为其分配正常范围的值以及空值。

	例如，您可以在 Nullable 变量中存储 -2,147,483,648 到 2,147,483,647 之间的任何值或空值
	同样，您可以在 Nullable 变量中赋值 true、false 或空值

	声明 可空值 类型的语法如下:
		< data_type> ? <variable_name> = null;


	空合并运算符 (??)
	>>	空合并运算符用于可空值类型和引用类型

	它用于将一个操作数转换为另一个可空(或不可空)值类型操作数的类型
	其中可以进行隐式转换

 */
			int? num1 = null;
			int? num2 = 45;

			double? num3 = new double?();
			double? num4 = 3.14157;

			bool? boolval = new bool?();

			// 显示值
			Console.WriteLine("Nullables at Show: {0}, {1}, {2}, {3}", num1, num2, num3, num4);
			Console.WriteLine("A Nullable boolean value: {0}", boolval);

			/*
			 * 如果第一个操作数的值为空
			 * 则该运算符返回第二个操作数的值
			 * 否则返回第一个操作数的值
			 */

			double? num5 = null;
			double? num6 = 3.14157;
			double num7;

			num7 = num5 ?? 5.34;
			Console.WriteLine(" Value of num3: {0}", num7);

			num7 = num6 ?? 5.34;
			Console.WriteLine(" Value of num3: {0}", num7);


/*
~	数组
	>>	数组存储的是固定大小、连续且类型相同的元素集合
	>>	数组通常用于存储数据集合
	>>	但通常将数组视为存储在连续内存位置的同类型变量的集合更为实用

	声明数组，可以使用以下语法 -
		datatype[] arrayName;

		>>	datatype 用于指定数组中元素的类型。
		>>	[ ] 指定数组的秩，秩指定数组的大小。
		>>	arrayName 指定数组的名称。

	初始化数组
	>>	声明数组并不会初始化内存中的数组
	>>	初始化数组变量后，就可以为数组赋值了。

		数组是引用类型
		因此需要使用 new 关键字来创建数组的实例
		例如:
			double[] balance = new double[10];

	多维数组
	>>	也称为矩形数组

	声明二维字符串数组
		string [,] names;

	声明三维 int 变量数组
		int [ , , ] m;

	交错数组
	>>	交错数组是数组的数组



 */
			// 初始化数组
			double[] balance = new double[10];
			// 赋值
			balance[0] = 4500.0;

			// 声明数组时赋值
			double[] balance2 = { 2.0, 32.0, 4209.24, 234.0 };

			// 创建并初始化数组
			int [] marks = new int[5] { 99, 98, 92, 97, 95};

			// 省略数组的大小
			int [] marks2 = new int[] { 99, 98, 92, 97, 95};

			// 将一个数组变量复制到另一个目标数组变量中
			int[] score = marks;

			// 案例
			int[] num = new int[10]; /* n 是一个包含 10 个整数的数组 */

			/* 初始化数组 n 的元素 */
			for ( i = 0; i < 10; i++ ) {
				num[ i ] = i + 100;
			}

			/* 输出每个数组元素的值 */
			for (j = 0; j < 10; j++ ) {
				Console.WriteLine("Element[{0}] = {1}", j, num[j]);
			}

			// 使用 foreach 遍历
			foreach (int temp in num) {
				i = temp - 100;
				Console.WriteLine("Element[{0}] = {1}", i, temp);
			}

			// 初始化二维数组
			int [,] array = new int [3,4] {
                {0, 1, 2, 3} , /* 行索引为 0 的初始化器 */
                {4, 5, 6, 7} , /* 行索引为 1 的初始化器 */
                {8, 9, 10, 11} /* 行索引为 2 的初始化器 */
            };

			// 初始化交错数组
			int[][] scores1 = new int[5][];
			for (i = 0; i < scores1.Length; i++) {
				scores1[i] = new int[4];
			}

			// 亦或者
			int[][] scores2 = new int[2][]{new int[]{92,93,94},new int[]{85,66,87,88}};

			// 案例
			/* 一个由 5 个整数组成的交错数组 */
			int[][] array2 = new int[][]{new int[]{0,0},new int[]{1,2},
				new int[]{2,4},new int[]{ 3, 6 }, new int[]{ 4, 8 } };

			/* 输出每个数组元素的值 */
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 2; j++) {
					Console.WriteLine("a[{0}][{1}] = {2}", i, j, array2[i][j]);
				}
			}


/*

~	字符串

	创建字符串对象
		通过将字符串文字赋值给字符串变量
		通过使用字符串类构造函数
		通过使用字符串连接运算符 (+)
		通过检索属性或调用返回字符串的方法
		通过调用格式化方法将值或对象转换为其字符串表示形式

	String 类的属性
		序号	属性 &说明
		1	Chars
		获取当前 String 对象中指定位置的 Char 对象

		2	Length
		获取当前 String 对象中的字符数

	String 类的方法
		序号	方法 &说明
		1	Clone()
		返回此字符串实例的引用。

		2	CompareOrdinal()
		通过计算字符串中对应字符的数值来比较两个字符串。

		3	Compare()
		比较使用指定规则(区分大小写、特定于文化等)连接两个指定的字符串对象。

		4	Concat()
		连接两个字符串对象。

		5	Contains()
		返回一个值，指示指定的字符串对象是否出现在此字符串中。

		6	CopyTo()
		将指定数量的字符从此字符串复制到字符数组中的指定位置。

		7	EndsWith()
		判断此字符串实例的末尾是否与指定字符串匹配。

		8	Equals()
		判断两个指定的 String 对象是否具有相同的值。

		9	Format()
		它将字符串中的格式项替换为相应对象的字符串表示形式。

		10	GetEnumerator()
		它检索一个可以遍历此字符串中各个字符的枚举器。

		11	GetHashCode()
		它返回此字符串的哈希码字符串。

		12	IndexOfAny()
		它在指定的字符数组中查找任意字符首次出现的索引。

		13	IndexOf()
		它返回此字符串中指定子字符串首次出现的从零开始的索引。

		14	Insert()
		在当前字符串的指定索引处插入一个字符串。

		15	IsNullOrEmpty()
		检查字符串是否为 null 或空。

		16	IsNullOrWhiteSpace()
		检查字符串是否为 null、空或仅包含空格。

		17	Join()
		使用指定的分隔符连接对象数组的字符串表示形式。

		18	LastIndexOf()
		返回字符串中指定子字符串最后一次出现的索引(从零开始)。

		19	PadLeft()
		使用指定字符填充字符串左侧，以达到给定的总长度。

		20	PadRight()
		使用指定字符填充字符串右侧，以达到给定的总长度。

		21	Remove()
		从当前字符串的指定位置开始，删除指定数量的字符。

		22	Replace()
		将所有出现的指定子字符串替换为另一个子字符串。

		23	Split()
		根据指定的分隔符将字符串拆分为多个子字符串。

		24	StartWith()
		判断此字符串实例的开头是否与指定字符串匹配。

		25	Substring()
		从指定索引处开始检索子字符串，直到字符串末尾。

		26	ToCharArray()
		转换将字符串转换为字符数组。

		27	ToLower()
		将字符串的所有字符转换为小写。

		28	ToString()
		返回对象的字符串表示形式。

		29	ToUpper()
		将字符串的所有字符转换为大写。

		30	TrimEnd()
		从当前字符串中删除所有尾随空格。

		31	TrimStart()
		从当前字符串中删除所有前导空格。

		32	Trim()
		该函数用于从当前字符串中删除所有前导和尾随空格。



 */
			//来自字符串文字和字符串连接
			string fname, lname;
			fname = "Rowan";
			lname = "Atkinson";

			char[] letters = {'H', 'e', 'l', 'l', 'o'};
			string[] sarray = {
				"Hello",
				"From",
				"Tutorials",
				"Point"
			};

			string fullname = fname + lname;
			Console.WriteLine("Full Name: {0}", fullname);

			//通过使用字符串构造函数 { 'H', 'e', 'l', 'l','o' };
			string greetings = new string(letters);
			Console.WriteLine("Greetings: {0}", greetings);

			string message = String.Join(" ", sarray);
			Console.WriteLine("Message: {0}", message);

			//格式化方法来转换值
			DateTime waiting = new DateTime(2012, 10, 10, 17, 58, 1);
			string chat = String.Format(
				"Message sent at {0:t} on {0:D}", waiting
			);
			Console.WriteLine("Message: {0}", chat);

			// 比较字符串
			string str1 = "This is test";
			string str2 = "This is text";

			if (String.Compare(str1, str2) == 0) {
				Console.WriteLine(
					str1 + " and " + str2 +  " are equal."
				);
			} else {
				Console.WriteLine(
					str1 + " and " + str2 + " are not equal."
				);
			}

			// 字符串包含字符串
			string str = "This is test";

			if (str.Contains("test")) {
				Console.WriteLine("The sequence 'test' was found.");
			}

			// 获取子字符串
			string str3 = "Last night I dreamt of San Pedro";
			Console.WriteLine(str3);
			string substr = str3.Substring(23);
			Console.WriteLine(substr);

			// 连接字符串
			string[] starray = new string[] {
				"Down the way nights are dark",
				"And the sun shines daily on the mountain top",
				"I took a trip on a sailing ship",
				"And when I reached Jamaica",
				"I made a stop"
			};

			string str4 = String.Join("", starray);
			Console.WriteLine(str4);


		}
	}
}










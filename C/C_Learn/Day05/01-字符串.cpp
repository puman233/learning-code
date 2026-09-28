//#include<stdio.h>
//
//#define MSG "I'm special"
//
//int main() {
//
//	/*
//
//		以 0 结尾的一串字符
//		0 等价于 '\0'	但不等于 '0'
//		0 标志着字符串的结束，但并不是字符串的一部分
//		计算字符串长度时 不包括 0
//		字符串以数组的形式存在，以数组或指针的形式访问
//			更多以指针形式
//		string.h 有更多字符串函数
//		
//	*/
//	char word[] = { 'H', 'e', 'l','l', 'o', '\0', };
//
//	int i;
//	for (i = 0; i < sizeof(word)/sizeof(word[0]); i++)
//	{
//		printf("%c", word[i]);
//	}
//	printf("\n");
//
//	char greeting[50] = "Hello, and"" how are" " you"" today!";
//	//与下面的代码等价：
//	char greeting2[50] = "Hello, and how are you today!";
//	for ( i = 0; i < sizeof(greeting)/sizeof(greeting[0]); i++)
//	{
//		printf("%c", greeting[i]);
//	}
//	printf("\n");
//	for ( i = 0; i < sizeof(greeting2)/sizeof(greeting2[0]); i++)
//	{
//		printf("%c", greeting2[i]);
//	}
//	printf("\n");
//
//	//如果要在字符串内部使用双引号，必须在双引号前面加上一个反斜杠（\）：
//	printf("\"Run, Spot, run!\" exclaimed Dick.\n");
//
//
//	// 字符串变量
//	char const* str = "Hello";
//	const char* str1 = "Hello";
//
//	const char* pt1 = "Something is pointing at me.";
//	// 与下列声明相同
//	const char ar1[] = "Something is pointing at me.";
//	printf("%s\n%s\n", pt1, ar1);
//
//	char wordhello[] = "Hello";
//	char line[10] = "Hello";	// 实际占据 6 个字节(结尾的 0 )
//
//	printf("%s\n%s\n", str, str1);
//
//	// 字符串地址
//	// #define MSG "I'm special"
//	/*
//	第一，pt和MSG的地址相同，而ar的地址不同
//	第二，虽然字符串字面量"I'm special"在程序的两个printf()函数中出现了两次，
//		但是编译器只使用了一个存储位置，而且与MSG的地址相同
//		编译器可以把多次使用的相同字面量储存在一处或多处
//	第三，静态数据使用的内存与ar使用的动态内存不同
//	*/
//	char ar[] = MSG;
//	const char* pt = MSG;
//	printf("address of \"I'm special\": %p \n", "I'm special");
//	printf("            address ar: %p\n", ar);
//	printf("            address pt: %p\n", pt);
//	printf("         address of MSG: %p\n", MSG);
//	printf("address of \"I'm special\": %p \n", "I'm special");
//	/*
//	为什么
//		1. 字符串字面量在程序中只出现了一次，编译器只使用了一个存储位置
//		2. 编译器可以把多次使用的相同字面量储存在一处或多处
//		3. 静态数据使用的内存与ar使用的动态内存不同
//	*/
//
//
//	return 0;
//}
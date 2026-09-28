//#include<stdio.h>
//
//#define DEF "A string defined by #define."
//
//int main() {
//
//	char word[8];
//	char word2[8];
//
//	// 防止野指针
//	// char* string;此时 string 是一个野指针，指向未知的内存地址，可能会导致程序崩溃或产生不可预测的行为
//	// 防止野指针，在声明时显式指明数组的大小，或者使用动态内存分配来分配内存空间
//	char word3[8];
//	char* string = word3;
//	
//	scanf_s("%7s", string, 8);
//
//	printf("%s\n", string);
//
//	// 空字符串
//	char bufffer[100] = "";
//	// 数组长度只有1
//	char bufferZero[] = "";
//
//	// 不安全
//	/*scanf_s("%s", word, 8);
//	scanf_s("%s", word2, 8);*/
//	scanf_s("%7s", word, 8);
//	scanf_s("%7s", word2, 8);
//
//	// 输出：hellowo##rld##
//	printf("%s##%s##\n", word, word2);
//	
//	// 在读取字符串时，scanf()	和转换说明%s只能读取一个单词
//	// 例如，输入 "Hello World" 时，scanf()和转换说明%s只会读取 "Hello"，
//	// 而不会读取 "World"
//
//	/*
//	fgets() 函数通过第2个参数限制读入的字符数来解决溢出的问题
//	
//	* fgets()函数的第2个参数指明了读入字符的最大数量。
//		如果该参数的值是n，那么fgets()将读入n-1个字符，
//		或者读到遇到的第一个换行符为止。
//	* 如果fgets()读到一个换行符，会把它储存在字符串中。
//	* fgets()函数的第3个参数指明要读入的文件。
//		如果读入从键盘输入的数据，则以stdin（标准输入）作为参数，
//		该标识符定义在stdio.h中。
//	* fgets()函数把换行符放在字符串的末尾
//	*/
//	/*
//	* fputs()
//	*	fputs() 函数的第2个参数指明要写入数据的文件。
//		如果要打印在显示器上，可以用定义在stdio.h中的stdout标准输出）作为该参数
//	* 与puts()不同，fputs()不会在输出的末尾添加换行符
//	*/
//
//	char words[14];
//	puts("Enter a string, please.");
//	fgets(words, 14, stdin);
//	printf("Your string twice (puts(), then fputs()):\n");
//	puts(words);
//	fputs(words, stdout);
//	puts("Enter another string, please.");
//	fgets(words, 14, stdin);
//	printf("Your string twice (puts(), then fputs()):\n");
//	puts(words);
//	fputs(words, stdout);
//	puts("Done.");
//
//	// 首先，如何处理掉换行符？
//	// 一个方法是在已储存的字符串中查找换行符，并将其替换成空字符
//	int i = 0;
//	while (words[i] != '\n') {
//		i++;
//	}
//	words[i] = '\0';
//
//	// 其次，如果仍有字符串留在输入行怎么办？
//	// 一个可行的办法是，如果目标数组装不下一整行输入，就丢弃那些多出的字符
//	while (getchar() != '\n')	// 读取但并不存储输入
//		continue;
//
//
//	// puts()函数的参数是一个字符串，它会在输出字符串后自动换行
//	// 其参数是一个字符串的首地址，或者说是一个指向字符串的指针
//	char str1[80] = "An array was initialized to me.";
//	const char* str2 = "A pointer was initialized to me.";
//
//	puts("I'm an argument to puts().");
//	puts(DEF);
//	puts(str1);
//	puts(str2);
//	puts(&str1[5]);	// 输出：ray was initialized to me.
//	puts(str2 + 4);	// 输出：inter was initialized to me.
//
//	
//	// printf()不会自动在每个字符串末尾加上一个换行符
//	printf("%s\n", DEF);
//	// 等效
//	puts(string);
//
//
//
//
//
//	return 0;
//}
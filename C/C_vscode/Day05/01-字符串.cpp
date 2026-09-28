#include<stdio.h>

int main() {

	/*

		以 0 结尾的一串字符
		0 等价于 '\0'	但不等于 '0'
		0 标志着字符串的结束，但并不是字符串的一部分
		计算字符串长度时 不包括 0
		字符串以数组的形式存在，以数组或指针的形式访问
			更多以指针形式
		string.h 有更多字符串函数
		
	*/
	char word[] = { 'H', 'e', 'l','l', 'o', '\0', };

	int i;
	for (i = 0; i < sizeof(word)/sizeof(word[0]); i++)
	{
		printf("%c", word[i]);
	}
	printf("\n");

	// 字符串变量
	char const* str = "Hello";
	const char* str1 = "Hello";
	char wordhello[] = "Hello";
	char line[10] = "Hello";	// 实际占据 6 个字节(结尾的 0 )

	printf("%s\n%s\n", str, str1);



	return 0;
}
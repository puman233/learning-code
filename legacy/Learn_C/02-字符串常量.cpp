#include<stdio.h>

int main(void) {

	//char* s = "Hello World";	// s 指针初始化指向 字符串常量	error
	char s[] = "Hello World";
	s[0] = 'B';

	printf("s[0] = %c\n", s[0]);
	printf("s = '%s'\n", s);


	/*
		数组：
			字符串作为本地变量空间自动被回收
		指针：
			字符串不知道位置
			处理参数
			动态分配空间
	*/
	char const* str = "Hello";
	char word[] = "Hello";

	/*
		char* 不一定是字符串
		字符串可以表达为 char* 的形式

		本意是指向字符的指针，可能指向字符的数组 (int*)
		只有它所指的字符数组有结尾 0 ，才能说它指的是字符串

	*/

	




	return 0;
}
#include<stdio.h>


int main(int argc, char const *argv[]) {
	

	// 第三行提示 超过数组长度
	/*char a[][10] = {
		"hello",
		"world",
		"skkkkkkkkskk",
		"123456789"
	}*/
	char const* a[] = {
		"hello",
		"world",
		"skkkkkkkkskk",
		"123456789"
	};

	int i;
	for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		printf("%s\n", a[i]);
	}

	for (i = 0; i < argc; i++)
	{
		printf("%d:%s\n", i, argv[i]);
	}









	return 0;
}
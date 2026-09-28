//#include<stdio.h>
//
//#define SLEN 40
//#define LIM 5
//
//int main(int argc, char const *argv[]) {
//	
//
//	// 第三行提示 超过数组长度
//	/*char a[][10] = {
//		"hello",
//		"world",
//		"skkkkkkkkskk",
//		"123456789"
//	}*/
//	// const指的是指针本身是常量，不能改变指针的指向，但可以改变指针所指向的内容。
//	char const* a[] = {
//		"hello",
//		"world",
//		"skkkkkkkkskk",
//		"123456789"
//	};
//
//	int i;
//	for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
//	{
//		printf("%s\n", a[i]);
//	}
//
//	// 显示命令行参数
//	for (i = 0; i < argc; i++)
//	{
//		// 0 号参数是程序名
//		printf("%d:%s\n", i, argv[i]);
//	}
//
//	// 字符串数组
//	const char* mytalents[LIM] = {	// 也可以使用 char mytalents[LIM][SLEN] = { ... }
//		"Adding numbers swiftly",
//		"Multiplying accurately", "Stashing data",
//		"Following instructions to the letter",
//		"Understanding the C language"
//	};
//	char yourtalents[LIM][SLEN] = {	// 也可以使用 const char* yourtalents[LIM] = { ... }
//		"Walking in a straight line",
//		"Sleeping", "Watching television",
//		"Mailing letters", "Reading email"
//	};
//
//
//	// 让用户输入自己的才能
//	puts("Let's compare talents.");
//	printf("%-36s  %-25s\n", "My Talents", "Your Talents");
//	// 显示才能列表
//	for (i = 0; i < LIM; i++)
//		printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
//	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
//		sizeof(mytalents), sizeof(yourtalents));
//
//
//
//
//	return 0;
//}
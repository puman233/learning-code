//#include<stdio.h>
//
//int main(void) {
//
//	//char* s = "Hello World";	// s 指针初始化指向 字符串常量	error
//	char s[] = "Hello World";
//	s[0] = 'B';
//
//	printf("s[0] = %c\n", s[0]);
//	printf("s = '%s'\n", s);
//
//
//	/*
//		数组：
//			字符串作为本地变量空间自动被回收
//		指针：
//			字符串不知道位置
//			处理参数
//			动态分配空间
//	*/
//	char const* str = "Hello";
//	char word[] = "Hello";
//
//	/*
//		char* 不一定是字符串
//		字符串可以表达为 char* 的形式
//
//		本意是指向字符的指针，可能指向字符的数组 (int*)
//		只有它所指的字符数组有结尾 0 ，才能说它指的是字符串
//
//	*/
//
//
//	/*
//	两者主要的区别是：数组名heart是常量，而指针名head是变量
//	*/
//	char heart[] = "I love Tillie!";
//	const char* head = "I love Millie!";
//
//	// 只有指针表示法可以进行递增操作
//	while (*(head) != '\0')    /* 在字符串末尾处停止*/
//		putchar(*(head++));    /* 打印字符，指针指向下一个位置 */
//
//	// 假设想让head 和heart 统一, 这使得head指针指向heart数组的首元素
//	head = heart;    /* 让head指向heart */
//	/*
//	head = heart; 不会导致head 指向的字符串消失，
//				这样做只是改变了储存在head 中的地址
//	*/
//	printf("\nhead = '%s'\n", head);
//	//heart = head;        /* 非法构造，不能这样写 */
//
//	//还可以改变heart数组中元素的信息：
//	heart[7] = 'M';
//	//或者
//	* (heart + 7) = 'M';
//	printf("\nheart = '%s'\n", heart);
//	printf("\nhead = '%s'\n", head);
//
//
//
//	return 0;
//}
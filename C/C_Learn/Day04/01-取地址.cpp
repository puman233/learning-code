//#include<stdio.h>
//
//int main() {
//
//	int a;
//
//	a = 6;
//
//	printf("sizeof(int)=%ld\n", sizeof(int));
//	printf("sizeof(double)=%ld\n", sizeof(double));
//	printf("sizeof(a)=%ld\n", sizeof(a));
//
//
//	int i = 0;
//
//	printf("0x%x\n", &i);	// 输出变量 i 的地址
//	printf("%p\n", &i);		// 输出变量 i 的地址
//
//	int *p;
//	p = (int*)&i;		// 强制类型转换
//	printf("p=0x%x\n", p);
//
//	// %lu 无符号长整型 unsigned long
//	printf("%lu\n", sizeof(&i));	// 指针类型的大小
//	printf("lu=%lu\n", sizeof(int*));	// 指针类型的大小
//
//
//
//	return 0;
//}
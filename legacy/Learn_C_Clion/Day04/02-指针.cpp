#include<stdio.h>

void f(int* p);
void g(int k);


int main() {

	int i = 0;

	int* p = &i;	// 指针变量 p 存储变量 i 的地址

	printf("p=%d\n", *p);	// 通过指针变量 p 访问变量 i 的值
	printf("&i=%p\n", &i);	// 输出变量 i 的地址

	f(&i);	// 传递变量 i 的地址给函数 f

	g(i);	// 传递变量 i 的值给函数 g



	return 0;
}

void f(int* p) {	// 指针变量 p 存储变量 i 的地址
	/*
		%p 用于输出指针变量的值（地址）
	*/
	printf("p=%p\n", p);	// 输出指针变量 p 的值（地址）
	printf("*p=%d\n", *p);	// 通过指针变量 p 访问变量 i 的值
	*p = 26;	// 通过指针变量 p 修改变量 i 的值

}

void g(int k) {		// 引用变量 k 存储变量 i 的值
	printf("k=%d\n", k);	// 通过引用变量 k 访问变量 i 的值
}

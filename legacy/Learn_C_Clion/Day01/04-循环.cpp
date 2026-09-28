#include<stdio.h>

int main() {
	// while 循环
	// 先判断循环条件，再执行循环体

	int x, n = 0;

	printf("请输入一个整数：");
	scanf_s("%d", &x);

	n++;
	x /= 10;
	x /= 10;
	while (x > 0) {
		n++;
		x /= 10;
	}
	printf("有%d位数\n", n);

	// do while 循环
	// 先执行循环体，再执行循环

	do
	{
		n++;
		x /= 10;
	} while (x > 0);
	
	printf("有%d位数\n", n - 1);
}
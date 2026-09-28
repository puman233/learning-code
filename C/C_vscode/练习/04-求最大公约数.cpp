#include<stdio.h>

/*
	a b i
	9 6 2
	1 3 3
	1 0 4

*/
int main() {
	int a, b, i, min;
	int gcd = 1;	// 最大公约数

	printf("请输入两个数：");
	scanf_s("%d %d", &a, &b);

	if (a<b)
	{
		min = a;
	}
	else {
		min = b;
	}
	for (i = 1; i <= min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
		}
	}

	printf("%d和%d的最大公约数是：%d\n", a, b, gcd);

	// 辗转相除法
	printf("-----求最大公约数 Pro-----\n");

	int num1, num2, t;
	int numGCD = 1;

	printf("请输入2个正整数：");
	scanf_s("%d %d", &num1, &num2);

	/*
		如果b = 0，计算结束，最大公约数为a
		否则，a % b的余数，a = b，让b = 余数
		循环...
	*/
	while (num2 != 0) {
		t = num1 % num2;
		num1 = num2;
		num2 = t;
		// 输出验证
		printf("a = %d, b = %d, t = %d\n", a, b, t);
	}
	printf("最大公约数为：%d\n", num1);

	return 0;
}
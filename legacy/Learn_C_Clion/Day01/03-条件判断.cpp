
#include <stdio.h>

int main() {

	/*
		if ( 条件成立 ){
			...
		}
		// 如果括号内的成立，则运行 大括号内的语句

		条件关系运算符：
			== 相等
			!= 不等
			>  大于
			<  小于
			>= 大于等于
			<= 小于等于

		优先级：
			算术运算符 > 条件关系运算符 > 赋值运算符
			判断是否相等(== & !=)优先级比其他低

	*/

	// 找零案例
	int price = 0, bill = 0;

	printf("请输入金额：");
	scanf_s("%d", &price);
	printf("请输入付款：");
	scanf_s("%d", &bill);

	if (bill >= price) {
		printf("应该找您：%d\n", bill - price);
	}
	else
	{
		printf("你的钱不够\n仍需：%d\n", price - bill);
	}
	

	// 若 if 或 else 后不加 大括号，只执行其后面的一句

	// 比大小
	int a, b, c, max = 0;
	printf("--比大小--\n请输入3个整数：\n");
	scanf_s("%d\n%d\n%d", &a, &b, &c);

	if (a > b)
	{
		if (a > c) {
			max = a;
		}
		else
		{
			max = c;
		}
	}
	else
	{
		if (b > c)
		{
			max = b;
		}
		else
		{
			max = c;
		}
	}
	printf("最大值为：%d\n", max);

	// 嵌套判断
	int x = 0;
	printf("输入x：");
	scanf_s("%d", &x);

	if (x > 10)
	{
		printf("x > 10\n");
	}
	else if (x == 10)
	{
		printf("x = 10\n");
	}
	else
	{
		printf("x < 10\n");
	}

	/*
		分支判断
		Switch case
		switch(type)中的 type 只能是整型
	*/
	int time = 0;

	printf("请输入一个0~24的整数：");
	scanf_s("%d", &time);

	time /= 6;
	switch (time) {
	case 0:
		printf("凌晨好\n");
		break;
	case 1:
		printf("上午好\n");
		break;
	case 2:
		printf("下午好\n");
		break;
	case 3:
		printf("晚上好\n");
		break;
	case 4:
		printf("深夜好\n");
		break;
	default:
		printf("您的输入有误\n");
		break;
	}
}

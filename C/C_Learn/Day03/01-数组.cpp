//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//#define PI 3.14159265358979323846
//#define MONTHS 12
//
//
//int main() {
//	/*
//		定义数组：
//			<type> 变量名称 [数量]
//			int grades[100];
//			double weight [10];
//		数组存放相同数据类型
//		创建后无法改变大小
//		数组的数据在内存中是按顺序排列的
//	*/
//
//	// 定义数组的语法：数据类型 数组名[数组元素个数];
//	/*
//	方括号（[]）表明candy、code和states
//	都是数组，方括号中的数字表明数组中的元素个数
//	*/
//
//	float candy[365];     /* 内含365个float类型元素的数组 */
//	char code[12];        /*内含12个char类型元素的数组*/
//	int states[50];       /*内含50个int类型元素的数组 */
//
//	int fix = 1;
//	float flax = PI * 2;
//
//	/*
//	如果不初始化数组，数组元素和未初始化的普通变量一样，其中储存的都是垃圾值；
//	但是，如果部分初始化数组，剩余的元素就会被初始化为0*/
//	const int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	int i;
//
//	for (size_t i = 0; i < MONTHS; i++)
//	{
//		printf("Month %2d has %2d days.\n", i + 1, days[i]);
//	}
//	printf("\n");
//	for (size_t i = 0; i < sizeof days / sizeof days[0]; i++)
//	{
//		printf("Month %2d has %d days.\n", i + 1, days[i]);
//	}
//
//	// 案例：输入1~9的整数，求各数出现的次数
//
//	const int num = 10;
//	int numX, numI;
//	// 初始化数组
//	int count[num] = { 0 };
//
//	printf("输入1~9的整数，求各数出现的次数，输入-1结束\n");
//	scanf_s("%d", &numX);
//	while (numX != -1) {
//		if (numX >= 0 && numX <= 9)
//		{
//			count[numX]++;
//		}
//		scanf_s("%d", &numX);
//	}
//	for (numI = 0; numI < num; numI++)
//	{
//		printf("%d:%d\n", numI, count[numI]);
//	}
//
//	return 0;
//
//	// 案例：求平均数
//	
//	int number[100];
//	int x, cnt = 0;
//	double sum = 0;
//
//	printf("输入-1退出\n");
//	scanf_s("%d", &x);
//
//	while (x != -1) {
//		number[cnt] = x;	// 存放数组
//		sum += x;
//		cnt++;	// 计数器++
//		scanf_s("%d", &x);
//	}
//	
//	double average = sum / cnt;
//
//	if (cnt > 0)
//	{
//		
//		for (i = 0; i < cnt; i++)
//		{
//			// 遍历数组
//			if (number[i] > average) {
//				printf("%d\n", number[i]);
//			}
//		}
//	}
//	
//	printf("和为：%.2f，输入了%d个数字，平均数为：%.2f\n", sum, cnt, average);
//
//
//	return 0;
//}
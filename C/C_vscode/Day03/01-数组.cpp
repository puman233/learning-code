#include<stdio.h>

int main() {
	/*
		定义数组：
			<type> 变量名称 [数量]
			int grades[100];
			double weight [10];
		数组存放相同数据类型
		创建后无法改变大小
		数组的数据在内存中是按顺序排列的
	*/

	// 案例：输入1~9的整数，求各数出现的次数

	const int num = 10;
	int numX, numI;
	// 初始化数组
	int count[num] = { 0 };

	scanf_s("%d", &numX);
	while (numX != -1) {
		if (numX >= 0 && numX <= 9)
		{
			count[numX]++;
		}
		scanf_s("%d", &numX);
	}
	for (numI = 0; numI < num; numI++)
	{
		printf("%d:%d\n", numI, count[numI]);
	}

	return 0;

	// 案例：求平均数
	
	int number[100];
	int x, cnt = 0;
	double sum = 0;

	printf("输入-1退出\n");
	scanf_s("%d", &x);

	while (x != -1) {
		number[cnt] = x;	// 存放数组
		sum += x;
		cnt++;	// 计数器++
		scanf_s("%d", &x);
	}
	
	int i;
	double average = sum / cnt;

	if (cnt > 0)
	{
		
		for (i = 0; i < cnt; i++)
		{
			// 遍历数组
			if (number[i] > average) {
				printf("%d\n", number[i]);
			}
		}
	}
	
	printf("和为：%.2f，输入了%d个数字，平均数为：%.2f\n", sum, cnt, average);


	return 0;
}
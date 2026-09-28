#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
	* ... 
	* return (*(int*)num2 - *(int*)num1);

	正数：交换位置

	负数：不交换或按当前顺序

	0：认为这两个元素相等

	由于 num2 - num1 是 num2 和 num1 的差值，
	如果 num2 大于 num1，结果是正数，
	这符合降序排列的要求。
*/
// 排序
int compare(const void* num1, const void* num2) {
	return(*(int*)num2 - *(int*)num1);	// 降序
}


int main() {
	/*
		商店

		同学 n	物品 m
		第 i 人有 wi 元，第 i 个物品 价格 ci元

		每个人最多买一个物品，每个物品最多被买一次

		求最多有多少人能买到物品

		用数组存放 
		每个人各自所带的钱数 和 物品价格
		wi[]				ci[]
		
		数组排序，从大到小，大钱-贵物，排序，
		还需考虑同学和物品谁更多

		wi[n] = 10 9 8 7 7 6 6 6 5 5 4 3 3 1 1
		yi[m] = 20 19 18 14 12 11 9 9 9 8 8 8 8 7 6 5 5 4 4 1

		10 9	n-1
		9 9
		8 8
		7 7
		7 6
		6 5
		6 5
		6 4
		5 4
		4 1
		// maxn = 10
	*/

	int n, m, i = 0;
	const long long int numx = 1000000000;
	// 数据太大，动态分配内存
	int* wi = (int*)malloc(numx);
	int* ci = (int*)malloc(numx);
	/*int wi[1000];
	int ci[1000];*/
	int maxn = 0;	// 最多人买到

	scanf_s("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &wi[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &ci[i]);
	}
	
	// 排序
	qsort(wi, n, sizeof(int), compare);
	qsort(ci, m, sizeof(int), compare);
	
	int min = n;
	int j = 0;
	i = 0;
	while (min > 0) {
		if (ci[j] != 0) {
			if (wi[i] - ci[j] >= 0)
				{
					maxn++;
					// 数组最大-数组最大
					i++;
					j++;

					// 减去消费的人和物品数量
					n--;
					m--;
				}
			else if (wi[i] - ci[j] < 0)
			{
				j++;
				m--;
			}
		}
		else
		{
			break;
		}
		// 判断循环条件
		if (n >= m)
		{
			min = m;
		}
		else
		{
			min = n;
		}
	}

	printf("%d", maxn);


	/*for (i = 0; i < n; i++)
	{
		printf("%d ", wi[i]);
	}
	for (i = 0; i < m; i++)
	{
		printf("%d ", ci[i]);
	}*/


	// 释放！
	free(wi), free(ci);

	return 0;

}

/*
	
#include <stdio.h>
#include <math.h>  // 包含 math.h 以使用 pow 函数

int main() {
	double base, exponent, result;

	// 输入底数和指数
	printf("Enter base and exponent: ");
	scanf("%lf %lf", &base, &exponent);

	// 计算乘方
	result = pow(base, exponent);

	// 输出结果
	printf("%.2lf^%.2lf = %.2lf\n", base, exponent, result);

	return 0;
}


*/
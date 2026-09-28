#include<stdio.h>

int main() {
	// 构造素数表
	
	//const int maxNumber = 25;
	const int maxNumber = 3000;
	int isPrime[maxNumber];	// 素数标记数组
	int i, x;

	// 初始化：假设所有数都是素数
	for (i = 0; i < maxNumber; i++)
	{
		isPrime[i] = 1;	// 默认 是素数
	}

	// 埃拉托斯特尼筛法 核心
	for (x = 2; x < maxNumber; x++)
	{
		if (isPrime[x])	// 如果x是素数
		{
			// 标记x的所有倍数为非素数
			for (i = 2; i*x < maxNumber; i++) {
				isPrime[i * x] = 0;	 // 标记为 非素数
			}
		}
	}
	// 输出所有素数
	for (i = 2; i < maxNumber; i++)
	{
		if (isPrime[i]) {
			printf("%d\t", i);
		}
	}
}
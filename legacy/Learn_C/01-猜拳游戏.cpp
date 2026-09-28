#include<stdio.h>
// 引用随机函数库
#include<stdlib.h>
#include<time.h>


int main() {

	/*
		rand() 召唤随机函数
		srand(time(0)) 使随机数拟真
	*/

	srand(time(0));
	int comNumber = rand() % 100 + 1;	// % 100 + 1 目的是取1~100内的数
	int count = 0, playerInput;

	do
	{
		printf("请猜1~100间的数：");
		scanf_s("%d", &playerInput);
		count++;
		if (playerInput > comNumber)
		{
			printf("猜 大 了\n");
		}
		else if (playerInput < comNumber)
		{
			printf("猜 小 了\n");
		}
	} while (playerInput != comNumber);

	printf("猜对，答案即为 %d，用了 %d 次\n", comNumber, count);

	return 0;
}
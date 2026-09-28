#include<stdio.h>

// 声明函数(在main前声明函数，才可在main中调用)
int search(int key, int n[], int numlength);

int main(void) {
	// sizeof 获取数组长度
	int a[] = { 2,3,4,5,1,9,3,0,24,543,24,12,24,34,45,6,5,76,7,76,86,7,876,876,86,13,3,76,8,0,98,75,4,8,2,1,1,2,3,3,4,55,1,6,7,342,8,90, };
	printf("%zd\n", sizeof(a));
	printf("%zd\n", sizeof(a[0]));

	// 计算数组长度
	const int length = sizeof(a) / sizeof(a[0]);
	printf("数组 元素个数：%d\n", length);

	// 数组不能简单赋值
	// 需采用遍历才能将一个数组赋值给另一个数组
	int b[length];
	printf("数组赋值结果：");
	for (int i = 0; i < length; i++)
	{
		b[i] = a[i];
		printf("%d ", b[i]);
	}
	printf("\n");

	// 搜索函数
	printf("---------------\n");

	int loc, numPlayer;

	printf("请输入一个数字：");
	scanf_s("%d", &numPlayer);
	loc = search(numPlayer, a, sizeof(a) / sizeof(a[0]));
	if (loc != -1)
	{
		printf("%d在%d位置上\n", numPlayer, loc);
		printf("%d在数组的第%d个位置\n", numPlayer, loc + 1);
	}
	else
	{
		printf("%d不存在\n", numPlayer);
	}

	return 0;
}

// 搜索函数
int search(int key, int n[], int numlength) {
	int ret = -1;
	int u;
	for (u = 0; u < numlength; u++)
	{
		if (n[u] == key) {
			ret = u;
			break;
		}
	}
	return ret;
}
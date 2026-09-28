#include<stdio.h>
#include<stdlib.h>

int main() {

	/*
		n 个宝箱
		第 i 个宝箱价值为 a[i]

		最大价值为 x
		最小价值为 y
		需保证 x - y <= k

		求能带走宝箱的最大总价值
	*/

	int n, k;

	scanf("%d %d", &n, &k);

	//int a[100];
	int* a = (int*)malloc(n * sizeof(int));


	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	//int count = n;

	// 从大到小排序
	// 这是冒泡排序
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp_max = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp_max;
			}
		}
	}

	int price_sum = 0;
	int price_max = 0;

	for (i = 0; i < n; i++)
	{
		price_sum = 0;
		for (j = i; j < n; j++)
			{
				if (a[i] - a[j] <= k) {
					price_sum += a[j];
				}
				else {
					break;
				}
			}
		if (price_sum > price_max)
		{
			price_max = price_sum;
		}
	}
	

	printf("%d\n", price_max);


	free(a);


	return 0;

}
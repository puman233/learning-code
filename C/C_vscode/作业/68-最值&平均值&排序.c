#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {

	int a[10], max, min, max_index = 0, min_index = 0;
	float average, sum = 0.0;

	// 大于并最接近平均值的数及其所在位置下标
	int closest = 0, closest_index = 0;

	// 小于平均值的数的个数
	int less_aver = 0;

	// 从小到大排序
	//int sort_a[10];

	int i, j;

	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	average = sum / 10.0;

	// 求最大值最小值
	max = a[0], min = a[0];
	for ( i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[j] > max) {
				max = a[j];
				max_index = j;
			}
			if (a[j] < min) {
				min = a[j];
				min_index = j;
			}
		}
	}

	// 求 closest
	closest = max;
	for ( i = 0; i < 10; i++)
	{
		// 从最大值开始 与平均值相减得到的绝对值 相减，找到绝对差值更小的数
		if (abs(closest - a[i]) < abs(closest - average) && closest > average) {
			closest = a[i];
			closest_index = i;
		}
	}
	
	for ( i = 0; i < 10; i++)
	{
		if (a[i] < average) {
			less_aver++;
		}
	}

	// sort
	for ( i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++) {
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("Maximum: a[%d]=%d\n", max_index, max);
	printf("Minimum: a[%d]=%d\n", min_index, min);
	printf("Average: %.1f\n", average);
	printf("Closest to: a[%d]=%d\n", closest_index, closest);
	printf("Less than: %d\n", less_aver);
	printf("Sort: ");
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}
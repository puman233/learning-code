#include<stdio.h>
#include<stdlib.h>

int main() {

	/*
		给 n 个正整数组成的数列 a[n]
		和 一个 正整数 m
		求出这个数列中的一个子区间[i, j]
		使得 a[i] + a[i+1] + ... + a[j] <= m

		如果多个区间满足条件
		输出i最小的区间


	*/

	int n, m;

	scanf("%d %d", &n, &m);

	int* a = (int*)malloc(n * sizeof(int));
	
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int array_sum = 0;
	int array_max = 0;
	int i_min = 0;
	int j_min = 0;

	for (i = 0; i < n; i++)
	{
		while (j < n && array_sum + a[j] <= m)
		{
			array_sum += a[j];
			j++;
		}
		if (array_sum > array_max)
		{
			array_max = array_sum;
			i_min = i;
			j_min = j - 1;
		}
		array_sum -= a[i];

	}


	printf("%d %d %d\n", i_min + 1, j_min + 1, array_max);










	free(a);


	return 0;
}
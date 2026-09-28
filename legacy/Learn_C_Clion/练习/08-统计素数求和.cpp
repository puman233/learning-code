#include<stdio.h>

int main() {

	 /*
		给2个正整数 M 和 N

		输出 M 和 N 间的素数个数以及它们的和，空格分隔

	 */

	int m, n;

	scanf_s("%d %d", &m, &n);

	int i = 0;
	int count = 0;
	int sum = 0;
	for (i = m; i <= n; i++)
	{
		// 判断素数
		int isPrime = 1;
		int k;
		for (k = 2; k < i - 1; k++)
		{
			if (i % k == 0) {
				isPrime = 0;	// 不是
				break;
			}
		}

		if (isPrime == 1)
		{
			count++;
			sum += i;
		}
	}

	printf("%d %d", count, sum);



	return 0;
}
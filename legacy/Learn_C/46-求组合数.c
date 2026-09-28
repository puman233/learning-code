#include<stdio.h>

int main() {

	int m, n;

	printf("Enter m: ");
	scanf("%d", &m);

	printf("Enter n: ");
	scanf("%d", &n);

	int result = 0;

	int i;

	int sum_m = 1, sum_n = 1, sum_m_n = 1;

	for (i = 0; i < m; i++)
	{
		sum_m *= (i + 1);
	}
	for (i = 0; i < n; i++)
	{
		sum_n *= (i + 1);
	}
	for (i = n-m; i > 0; i--)
	{
		sum_m_n *= i;
	}

	result = sum_n / (sum_m * sum_m_n);

	printf("result=%d\n", result);



	return 0;
}
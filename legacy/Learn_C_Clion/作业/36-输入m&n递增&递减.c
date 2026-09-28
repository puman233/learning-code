#include<stdio.h>

int main() {

	long int m, n;

	scanf("%ld %ld", &m, &n);

	long int i = 0;
	if (m > n) {
		for (i = m; i >= n; i--)
		{
			printf("%ld\n", i);
		}
	}
	else if (m < n)
	{
		for (i = m; i <= n; i++)
		{
			printf("%ld\n", i);
		}
	}
	else
	{
		printf("%ld\n", m);
	}





	return 0;
}
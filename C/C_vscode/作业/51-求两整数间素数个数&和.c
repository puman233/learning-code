#include<stdio.h>

int main() {

	int m, n;

	printf("Input m: ");
	scanf("%d", &m);
	
	printf("Input n: ");
	scanf("%d", &n);

	int count = 0, sum = 0;

	int i = 0, k = 2;

	for (i = m; i <= n; i++) {
		int isPrime = 1;

		if (i < 2)
		{
			continue;
		}
		for (k = 2; k <= i / 2; k++)
		{
			if (i % k == 0) 
			{
				isPrime = 0;
				break;
			}
			
		}
		if (isPrime == 1)
		{
			count++;
			sum += i;
		}
		
	}

	printf("count=%d, sum=%d\n", count, sum);










	return 0;
}
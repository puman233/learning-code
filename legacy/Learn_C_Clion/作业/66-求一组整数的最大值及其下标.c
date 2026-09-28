#include<stdio.h>

int main() {

	int n, i;

	int num[10];

	printf("Input n: ");
	scanf("%d", &n);

	printf("Input %d integers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	int max = num[0], max_index = 0;

	for ( i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			if (num[j] > max) {
				max = num[j];
				max_index = j;
			}
		}
	}

	printf("max=%d, index=%d\n", max, max_index);









	return 0;
}
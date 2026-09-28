#include<stdio.h>
#include<stdlib.h>


int main() {

	int n;

	scanf_s("%d", &n);

	// ĘäČëĹĹÁĐ
	int* p = (int*)malloc(n * sizeof(int));

	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &p[i]);
	}

	int m;

	scanf_s("%d", &m);

	int* result = (int*)malloc(m * sizeof(int));

	int sum = 0;
	for (i = 0; i < m; i++)
	{
		int left, right;
		scanf_s("%d %d", &left, &right);
		int j = 0;
		sum = 0;
		for (j = left; j <= right; j++)
		{
			sum += p[j-1];
		}
		result[i] = sum;
	}

	for (i = 0; i < m; i++)
	{
		printf("%d\n", result[i]);
	}



	free(p);
	free(result);



	return 0;
}
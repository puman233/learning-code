#include<stdio.h>

int main() {

	int f1 = 1, f2 = 1, f3;

	int i, n, count = 1;

	scanf("%d", &n);


	for (i = 0; i < n; i++)
	{
		printf("%15d", f1);
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;

		if (count % 4 == 0)
		{
			printf("\n");
		}
		count++;
	}








	return 0;
}
#include<stdio.h>

int main() {

	int a[2][3] = { 0 };

	int i, j;
	
	printf("please input array a:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int b[3][2] = { 0 };

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++)
		{
			b[i][j] = a[j][i];
		}
	}

	printf("array b:\n");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++)
		{
			printf("%5d", b[i][j]);
		}
		printf("\n");
	}
	







	return 0;
}
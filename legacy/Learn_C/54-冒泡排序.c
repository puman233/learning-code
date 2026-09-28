#include<stdio.h>

int main() {

	int num[10] = { 0 };

	printf("Input 10 numbers:\n");

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);

	}

	int j = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9; j++) {
			
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	printf("The sorted numbers:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", num[i]);
	}



	return 0;
}
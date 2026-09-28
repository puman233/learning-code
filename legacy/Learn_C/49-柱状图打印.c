#include<stdio.h>

int main() {

	int narr[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &narr[i]);
	}

	for (i = 0; i < 5; i++)
	{
		while (narr[i] > 0) {
			printf("*");
			narr[i]--;
		}
		printf("\n");
	}






	return 0;
}
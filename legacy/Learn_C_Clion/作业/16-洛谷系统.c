#include<stdio.h>


int main() {

	int n = 0;

	scanf("%d", &n);

	int timeLocal = n * 5;
	int timeLuogu = 11 + n * 3;

	if (timeLocal > timeLuogu)
	{
		printf("Luogu");
	}
	else
	{
		printf("Local");
	}










	return 0;
}
#include<stdio.h>

int main() {

	int a, b, c;
	int sum = 0, x = 0;
	float average = 0;

	scanf("%d %d %d", &a, &b, &c);

	sum = a + b + c;
	x = a * b * c;

	float n = 3.0;

	average = sum / n;

	printf("%d %d %.2f", sum, x, average);

	return 0;
}
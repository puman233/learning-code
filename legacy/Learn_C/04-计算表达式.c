#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {

	float x, b, result = 0;

	scanf("%f %f", &x, &b);

	x = abs(x);

	result = sqrt(x) + b;

	printf("%.2f", result);


	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

	int ta, n;

	printf("Please input a and n:");

	scanf("%d,%d", &ta, &n);

	int a = ta;
	int sum = 0;

	int i = 0;
	/*
		2
		2%10=2	2+2*10=22
				22%10=2	22+2*100=222


	*/
	int temppow = 1;
	for (i = 0; i < n; i++)
	{
		sum += a;
		temppow *= 10;
		a = temppow * (a % 10) + a % temppow;
	}

	printf("%d+%d+...=%d\n", ta, ta * 10 + ta, sum);






	return 0;
}
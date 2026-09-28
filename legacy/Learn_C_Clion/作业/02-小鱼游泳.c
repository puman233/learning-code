#include<stdio.h>

int main() {
	/*
	从 a 时 b 分一直游泳到当天的 c 时 d 分
	*/
	int a, b, c, d, e = 0, f = 0;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (d > b)
	{
		f = d - b;
		e = c - a;
	}
	else if (d < b)
	{
		f = d + 60 - b;
		e = c - a - 1;
	}

	printf("%d %d\n", e, f);

	return 0;
}
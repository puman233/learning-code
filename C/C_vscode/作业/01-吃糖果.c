#include<stdio.h>

int main() {

	int n, t, m, price = 3;


	scanf("%d", &n);
	n *= 10;

	t = n / price;

	m = n % price;



	printf("%d %d\n", t, m);

	return 0;



}
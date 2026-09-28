#include<stdio.h>

int main() {
	
	int n;

	int i = 0;

	scanf("%d", &n);

	// ËØÊı
	int isPrime = 1;

	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			isPrime = 0;
			break;
		}
	}

	if (isPrime == 1) {
		printf("Yes.\n");
	}
	else {
		printf("No.\n");
	}




	return 0;
}
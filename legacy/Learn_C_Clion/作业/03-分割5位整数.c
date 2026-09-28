#include<stdio.h>

int main() {

	int num, mask = 1, count;

	scanf("%d", &num);

	
	// 先数多少位
	count = num;
	while (count > 9) {
		count /= 10;
		mask *= 10;
	}

	do
	{
		int result = num / mask;	// 取最左边的数
		printf("%d   ", result);

		num %= mask;
		
		mask /= 10;
	} while (mask > 0);

	return 0;

}
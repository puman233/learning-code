#include<stdio.h>

int main() {

	int sum = 0;
	int num = 0;
	printf("Input integers: ");
	while (1)
	{
		scanf("%d", &num);

		if (num <= 0)
		{
			break;
		}
		else if (num % 2 != 0)
		{
			sum += num;
		}
	}

	printf("The sum of the odd numbers is %d\n", sum);



	return 0;
}
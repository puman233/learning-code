#include<stdio.h>

int main() {

	int n = 0;

	scanf("%d", &n);

	int i = 0;
	//int mask = 10000;
	if (n >= 10000 && n <= 99999)
	{
		int lastDigit = n % 10;
		int firstDigit = n / 10000;
		int sencondDigit = (n / 1000) % 10;
		int fourthDigit = (n / 10) % 10;
		if (firstDigit == lastDigit && sencondDigit == fourthDigit)
		{
			printf("Yes\n");
			/*while (i < 5) {
				printf("%d\n", n % mask);
				mask /= 10;
				i++;
			}
			*/
		}
		/*
			12645 / 10000 = 1
			12645 % 10000 = 2645
			24645 / 1000 = 2
			24645 % 1000 = 645
			645 / 100 = 6
			645 % 100 = 45
			45 / 10 = 4
			45 % 10 = 5



		*/
		else
		{
			printf("No\n");
			//int temp = n;
			for (i = 0; i < 5; i++) {
				if (n % 10 == 0)
				{

				}
				else
				{
					printf("%d", n % 10);
				}
				
				n /= 10;
				//mask /= 10;
			}
			/*while (temp > 9) {
				temp /= mask;
				printf("%d", temp);
				temp %= mask;
				mask /= 10;
			}*/
		}
	}
	else
	{
		printf("Failure\n");
	}
	



	return 0;
}
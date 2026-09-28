#include<stdio.h>

int main() {

	int k; 

	scanf("%d", &k);

	int count = 0, sum = 0;

	while (count < 10)
	{
		if (k < 13)
		{
			break;
		}
		else if (k % 13 == 0) {
			sum += k;
			count++;
			k--;
		}
		else if (k % 17 == 0)
		{
			sum += k;
			count++;
			k--;
		}
		else
		{
			k--;
		}
	}
	printf("%d\n", sum);




	return 0;
}
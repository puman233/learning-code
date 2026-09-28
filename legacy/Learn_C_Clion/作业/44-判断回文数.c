#include<stdio.h>

int main() {

	int tnum;

	scanf("%d", &tnum);

	int num = tnum;
	int temp, dnum = 0;
	
	while(num > 0) {
		temp = num % 10;
		num = num / 10;
		dnum = dnum * 10 + temp;
	}

	printf("%d\n", dnum);

	if (dnum == tnum)
	{
		printf("%d is huiwen", tnum);
	}
	else
	{
		printf("%d is not huiwen", tnum);
	}







	return 0;
}
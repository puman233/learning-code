//#include<stdio.h>
//
//int main() {
//
//	int n;
//
//	scanf("%d", &n);
//
//	int i = 2, j = 2, count = 0, isPrime = 1, h = 0;
//
//	for (i = 2; i <= n; i++)
//	{
//		isPrime = 1;
//		for (j = 2; j <= i / 2; j++)
//		{
//			if (i % j == 0)
//			{
//				isPrime = 0;
//				break;
//			}
//		}
//		if (h == 10)
//		{
//			printf("\n");
//			h = 0;
//		}
//		if (isPrime == 1)
//		{
//			count++;
//			h++;
//			printf("%-5d", i);
//		}
//	}
//
//	printf("\nThe total is %d\n", count);
//
//
//
//
//
//
//	return 0;
//}
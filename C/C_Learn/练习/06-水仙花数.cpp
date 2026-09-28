//#include<stdio.h>
//#include<math.h>
//
//int main() {
//
//	/*
//		水仙花数是指一个N位正整数（N>=3），
//		它的每个位上的数字的N次幂之和等于它本身。
//		例如：153=1(*3)+5(*3)+3(*3)
//		本题要求编写程序，
//		计算所有N位水仙花数。
//
//	*/
//
//	int n = 0;
//	scanf_s("%d", &n);
//
//	int i = 0;
//	int first = int(pow(10, n - 1)), end = int(pow(10, n));
//	for (i = first; i < end; i++)
//	{
//		int temp = i;
//		int count = n;
//		int sum = 0;
//		while (count > 0) {
//			// d取最后一位
//			int d = temp % 10;
//			// 去i最后一位
//			temp /= 10;
//			sum += pow(d, n);
//			
//			count--;
//		}
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//		
//	}
//
//
//
//
//
//
//	return 0;
//}
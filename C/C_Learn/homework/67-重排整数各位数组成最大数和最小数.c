//#include<stdio.h>
//
//int main() {
//
//	int i, j, count = 0;
//	long int n, num[1000];
//
//	scanf("%ld", &n);
//
//	int tn = n;
//	while (tn > 0) {
//		tn /= 10;
//		// 记录位数
//		count++;
//	}
//
//	tn = n;
//	for ( i = 0; i < count; i++)
//	{
//		// 从个位开始取 转成数组
//		num[i] = tn % 10;
//		tn /= 10;
//	}
//
//	// 从小到大排
//	for ( i = 0; i < count - 1; i++)
//	{
//		for ( j = i+1; j < count; j++)
//		{
//			if (num[i] > num[j]) {
//				int temp = num[j];
//				num[j] = num[i];
//				num[i] = temp;
//			}
//		}
//	}
//
//	long int max = 0, min = 0;
//
//	for ( i = 0; i < count; i++)
//	{
//		// 先乘 10 再加下一位数
//		min = min * 10 + num[i];
//		
//	}
//
//	for ( i = count - 1; i >= 0; i--)
//	{
//		max = max * 10 + num[i];
//		
//	}
//
//	printf("%ld %ld", max, min);
//
//
//
//
//
//
//	return 0;
//}
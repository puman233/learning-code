//#include<stdio.h>
//
//int main() {
//
//	int n;
//
//	scanf("%d", &n);
//
//	int a[12][12] = { 0 };
//
//	// 需求：输出 n + 1 行 杨辉三角
//	// 输出：每个数字占 4 位
//
//	// 计算杨辉三角
//	int i, j;
//
//	a[0][0] = 1;
//	for ( i = 1; i < n+1; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//		for ( j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//
//	int count = n * 2;
//	for ( i = 0; i < n+1; i++)
//	{
//		int tcount = count;
//		while (tcount > 0) {
//			printf(" ");
//			tcount--;
//		}
//		for ( j = 0; j <= i; j++)
//		{
//			printf("%4d", a[i][j]);
//		}
//		printf("\n");
//		count -= 2;
//	}
//
//
//
//
//
//
//
//
//
//
//	return 0;
//}
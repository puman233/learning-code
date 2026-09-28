//#include<stdio.h>
//
//int main() {
//
//	int n, i, j;
//	int ifzero = 0;
//	int a[6][6];
//
//	printf("Input n:");
//	scanf("%d", &n);
//
//	printf("Input array:\n");
//	for ( i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	
//	/*
//
//		1 2 3 0
//		0 4 5 7
//		1 0 0 8
//		0 6 0 9
//
//		10
//		20 21
//		30 31 32
//	*/
//
//	// 细节从第 1 行开始判断
//	for ( i = 1; i < n; i++)
//	{
//		ifzero += a[i][i - 1];
//	}
//
//	if (ifzero == 0)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//
//
//
//
//
//
//
//	return 0;
//}
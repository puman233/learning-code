//#include<stdio.h>
//#include<stdlib.h>
//
//int compare(const void* num1, const void* num2) {
//	return (*(int*)num2 - *(int*)num1);
//}
//
//
//int main() {
//
//	/*
//		3 6 5 
//		3 1 
//		1 2 
//		1 2 
//
//		11
//
//		
//	*/
//	// 垛口 每单位高度增加的钱 每单位高度减少的钱
//	int n, x, y;
//
//	scanf_s("%d %d %d", &n, &x, &y);
//
//	//const int v = n;
//	// 垛堞被编号为 1 ~ N,	垛堞i的高度为Mi
//	int* m = (int*)malloc(n * sizeof(int));
//
//	// 垛堞的高度更改为这些高度 Bn
//	int* b = (int*)malloc(n * sizeof(int));
//
//	int cost = 0;
//
//
//
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d %d", &m[i], &b[i]);
//	}
//
//	qsort(m, n, sizeof(int), compare);
//	qsort(b, n, sizeof(int), compare);
//
//	for (i = 0; i < n; i++)
//	{
//		if (m[i] > b[i])
//		{
//			cost += (m[i] - b[i]) * y;
//		}
//		else if (m[i] < b[i])
//		{
//			cost += (b[i] - m[i]) * x;
//		}
//	}
//
//
//	printf("%d", cost);
//
//
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//
//int main() {
//
//	/*
//		长度为 n 的整数排列 p[i]
//
//		每次花费 区间长度 即 r - l + 1 的代价
//		选择任意区间 [l, r] 从小到大排序
//
//		进行若干次操作
//		直到 p 中的元素 从 1 到 n 升序排列
//		即对于 1 到 n 的每一个 i, 都有 p[i] = i
//
//		求最小总花费
//
//	*/
//
//	// 组数
//	int t;
//	int n;
//
//	scanf("%d", &t);
//
//	int** p = (int**)malloc(n * sizeof(int*));
//
//	// 输入排列
//	int i = 0, j = 0;
//	for (i = 0; i < t; i++)
//	{
//		// 每组询问 第一行 输入 n 代表数组元素个数
//		
//		// 第二行 输入 n 个整数代表排列 p
//		scanf("%d", &n);
//
//		p[i] = (int*)malloc(n * sizeof(int));
//		
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &p[i][j]);
//		}
//	}
//
//
//
//
//
//
//	for (i = 0; i < n; i++)
//	{
//		free(p[i]);
//	}
//
//	return 0;
//}
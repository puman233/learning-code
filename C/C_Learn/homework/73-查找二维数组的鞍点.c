//#include<stdio.h>
//
//int main() {
//
//	int a[1000][10] = { 0 };
//	// 鞍点
//	int saddle = 0;
//	int m, n;
//
//	scanf("%d*%d", &m, &n);
//	
//	int i, j, k;
//	for ( i = 0; i < m; i++)
//	{
//		for ( j = 0; j < n; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//
//	// 查找鞍点
//	//int max = a[0][0], min = a[0][0];
//	int row_max;
//	int row_max_index = 0, column_min_index = 0;
//	int is_saddle = 1;	// 默认为鞍点
//	for ( i = 0; i < m; i++)
//	{
//		// 切记每轮重置 1 否则为 None
//		is_saddle = 1;
//		row_max = a[i][0];
//		// 找 行 最大
//		for (j = 0; j < n; j++) {
//			if (row_max < a[i][j])
//			{
//				row_max = a[i][j];
//				column_min_index = j;
//				row_max_index = i;
//			}
//		}
//
//		// 判断 是否列最小
//		for (k = 0; k < m; k++)
//		{
//			// 只要 row_max 大于 列 中除自己以外的数
//			// 则不是鞍点
//			if (row_max > a[k][column_min_index]) {
//				is_saddle = 0;
//				break;
//			}
//		}
//
//		// 以下无意义
//		//if (column_min == row_max)
//		//{
//		//	is_saddle = 1;
//		//	//row_max_index = i;
//		//	//column_min_index = j;
//		//	break;
//		//}
//
//		if (is_saddle == 1)
//		{
//			saddle = a[row_max_index][column_min_index];
//			printf("Array[%d][%d]=%d\n", row_max_index, column_min_index, saddle);
//			break;
//		}
//
//	}
//
//	if (is_saddle == 0)
//	{
//		printf("None\n");
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
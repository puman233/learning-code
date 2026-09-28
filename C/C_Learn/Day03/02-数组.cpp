//#include<stdio.h>
//
//// 声明函数(在main前声明函数，才可在main中调用)
//int search(int key, int n[], int numlength);
//
//// 处理多维数组的函数
//#define COLS 4
//#define ROWS 3
//void sum_rows(int ar[][COLS], int rows);
//void sum_cols(int ar[][COLS], int rows);
//int sum2d(int ar[][COLS], int rows);
//
//
//int main(void) {
//	// sizeof 获取数组长度
//	int a[] = { 2,3,4,5,1,9,3,0,24,543,24,12,24,34,45,6,5,76,7,76,86,7,876,876,86,13,3,76,8,0,98,75,4,8,2,1,1,2,3,3,4,55,1,6,7,342,8,90, };
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n", sizeof(a[0]));
//
//	// 计算数组长度
//	const int length = sizeof(a) / sizeof(a[0]);
//	printf("数组 元素个数：%d\n", length);
//
//	// 数组不能简单赋值
//	// 需采用遍历才能将一个数组赋值给另一个数组
//	int b[length];
//	printf("数组赋值结果：");
//	for (int i = 0; i < length; i++)
//	{
//		b[i] = a[i];
//		printf("%d ", b[i]);
//		if (i % 6 == 0)
//		{
//			printf("\n");
//		}
//	}
//	printf("\n");
//
//	// 搜索函数
//	printf("---------------\n");
//
//	int loc, numPlayer;
//
//	printf("请输入一个数字：");
//	scanf_s("%d", &numPlayer);
//	loc = search(numPlayer, a, sizeof(a) / sizeof(a[0]));
//	if (loc != -1)
//	{
//		printf("%d在%d位置上\n", numPlayer, loc);
//		printf("%d在数组的第%d个位置\n", numPlayer, loc + 1);
//	}
//	else
//	{
//		printf("%d不存在\n", numPlayer);
//	}
//
//	// 多维数组
//	int junk[ROWS][COLS] = {
//			 { 2, 4, 6, 8 },
//			 { 3, 5, 7, 9 },
//			 { 12, 10, 8, 6 }
//	};
//
//	sum_rows(junk, ROWS);
//	sum_cols(junk, ROWS);
//	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
//
//	return 0;
//}
//
//// 搜索函数
//int search(int key, int n[], int numlength) {
//	int ret = -1;
//	int u;
//	for (u = 0; u < numlength; u++)
//	{
//		if (n[u] == key) {
//			ret = u;
//			break;
//		}
//	}
//	return ret;
//}
//
//// 函数和多维数组
//// 计算二维数组每行的和
//void sum_rows(int ar[][COLS], int rows)
//{
//	int r;
//	int c;
//	int tot;
//
//	for (r = 0; r < rows; r++)
//	{
//		tot = 0;
//		for (c = 0; c < COLS; c++)
//			tot += ar[r][c];
//		printf("row %d: sum = %d\n", r, tot);
//	}
//}
//// 计算二维数组每列的和
//void sum_cols(int ar[][COLS], int rows)
//{
//	int r;
//	int c;
//	int tot;
//
//	for (c = 0; c < COLS; c++)
//	{
//		tot = 0;
//		for (r = 0; r < rows; r++)
//			tot += ar[r][c];
//		printf("col %d: sum = %d\n", c, tot);
//	}
//}
//// 计算二维数组所有元素的和
//int sum2d(int ar[][COLS], int rows)
//{
//	int r;
//	int c;
//	int tot = 0;
//
//	for (r = 0; r < rows; r++)
//		for (c = 0; c < COLS; c++)
//			tot += ar[r][c];
//
//	return tot;
//}
//

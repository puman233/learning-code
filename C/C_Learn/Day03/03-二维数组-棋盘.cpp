//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//int main() {
//
//	// 二维数组的列必须给出
//
//	// 案例：棋盘游戏
//
//	const int size = 3;
//	int board[size][size];
//	int i, j;
//	// 下棋为O，则为0；下棋为X，则为1；-1为平局
//	int numO, numX, result = -1;
//
//	printf("输入3x3矩阵（0代表O，1代表X）：\n");
//	printf("例如：\n0 1 0\n1 0 1\n0 1 0\n");
//	printf("输入矩阵：\n");
//
//	// 读入矩阵
//	for ( i = 0; i < size; i++)
//	{
//		for (j = 0; j < size; j++) {
//			scanf_s("%d", &board[i][j]);
//		}
//	}
//
//	// 检查行
//	for (i = 0; i < size; i++)
//	{
//		numO = numX = 0;
//		for (j = 0; j < size; j++)	// 列数增加检查 1 or 0
//		{
//			if (board[i][j] == 0) {
//				numO++;
//			}
//			else
//			{
//				numX++;
//			}
//		}
//		// 判断输赢
//		if (numO == size)
//		{
//			result = 0;
//		}
//		else if (numX == size)
//		{
//			result = 1;
//		}
//	}
//
//	if (result == -1)
//	{
//		// 检查列
//		for (j = 0; j < size; j++)
//		{
//			numO = numX = 0;	// 定义棋数为0
//			for (i = 0; i < size; i++)	// 行数增加检查 1 or 0
//			{
//				if (board[i][j] == 0) {
//					numO++;
//				}
//				else
//				{
//					numX++;
//				}
//			}
//			// 判断输赢
//			if (numO == size)
//			{
//				result = 0;
//			}
//			else if (numX == size)
//			{
//				result = 1;
//			}
//		}
//	}
//	
//	if (result == -1)
//	{
//		// 检查对角线，即检查 00 11 22 或02 11 20
//		// 检查 正对角线
//		numO = numX = 0;
//		for ( i = 0; i < size; i++)
//		{
//			if (board[i][i] == 0) {
//				numO++;
//			}
//			else
//			{
//				numX++;
//			}
//		}
//		
//		// 判断输赢
//		if (numO == size)
//		{
//			result = 0;
//		}
//		else if (numX == size)
//		{
//			result = 1;
//		}
//
//		if (result == -1)
//		{
//			// 检查 对对角线
//			numO = numX = 0;
//			for (i = 0; i < size; i++)
//			{
//				if (board[i][size - 1 - i] == 0) {
//					numO++;
//				}
//				else
//				{
//					numX++;
//				}
//			}
//			// 判断输赢
//			if (numO == size)
//			{
//				result = 0;
//			}
//			else if (numX == size)
//			{
//				result = 1;
//			}
//		}
//	}
//	
//	if (result == -1)
//	{
//		printf("平局\n");
//	}
//	else if(result == 0)
//	{
//		printf("O棋胜\n");
//	}
//	else
//	{
//		printf("X棋胜\n");
//	}
//
//}
//#include<stdio.h>
//
//int main() {
//
//	int num[3][4] = { 0 };
//
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++) {
//			scanf("%d", &num[i][j]);
//		}
//	}
//
//	int max = num[0][0], row = 0, colum = 0;
//
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++) {
//			if (num[i][j] > max)
//			{
//				max = num[i][j];
//				row = i;
//				colum = j;
//			}
//		}
//	}
//
//	printf("max=%d,row=%d,colum=%d", max, row, colum);
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
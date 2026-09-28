//#include<stdio.h>
//
//int main() {
//	/*
//		整数求逆
//			利用 %10 取最右边的数
//			利用 /10 去最右边的数
//	*/
//	int x, read, result = 0;
//
//	printf("请输入一个整数：");
//	scanf_s("%d", &x);
//	while (x > 0) {
//		// 取最右边
//		read = x % 10;
//
//		printf("read = %d\n", x);
//
//		result = result * 10 + read;
//		// 去最右边
//		x /= 10;
//		
//	}
//	printf("求逆结果为：%d\n", result);
//
//	// 以上的程序不能逆序 末尾是 0 的情况
//
//	printf("---逆序 pro---\n");
//
//	int numPlayer;
//	printf("请输入整数：");
//	scanf_s("%d", &numPlayer);
//
//	int numConst = numPlayer;
//	int mask = 1;
//	// 此时用while循环先判定条件，再增量mask
//	while (numConst > 9) {
//		numConst /= 10;
//		mask *= 10;
//	}
//
//	printf("numPlayer = %d, mask = %d\n", numPlayer, mask);
//
//	do
//	{
//		int result = numPlayer / mask;	// 取最左边的数
//		printf("%d", result);
//		/*if (mask > 9)
//		{
//			printf(" ");
//		}*/
//		// 取最右边
//		numPlayer %= mask;
//		// 修改mask条件
//		mask /= 10;
//	} while (mask > 0);
//
//	return 0;
//}
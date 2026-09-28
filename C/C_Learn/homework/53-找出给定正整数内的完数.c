//#include<stdio.h>
//
//int main() {
//
//	/*
//		一个数如果恰好等于它的因子之和，
//		这个数就称为“完数”。
//		
//		例如：6=1+2+3。
//		
//		编程找出2-给定正整数以内的所有完数。
//	*/
//
//	int m;
//
//	printf("Please input m:");
//	scanf("%d", &m);
//
//	int i, j;
//
//	for (i = 2; i <= m; i++) {
//		int sum = 0;
//		int num[100], arr = 0;
//
//		for (j = 1; j <= i / 2; j++) {
//			if (i % j == 0) {
//				sum += j;
//				num[arr++] = j;
//			}
//		}
//
//		if (sum == i) {
//			printf("%d=1", i);
//			int temp = arr;
//			for (arr = 1; arr < temp; arr++) {
//				printf("+%d", num[arr]);
//			}
//			printf("\n");
//		}
//	}
//
//
//
//
//
//
//	return 0;
//}
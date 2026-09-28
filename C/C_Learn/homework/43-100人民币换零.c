//#include<stdio.h>
//
//int main() {
//
//	/*
//		5元 + 1元 + 0.5元 >> 100张
//		各有一张
//	*/
//
//	int five_yuan = 0, one_yuan = 0, half_yuan = 0;
//	int count = 0;
//
//	for (five_yuan = 1; five_yuan <= 20; five_yuan++) {
//		for (one_yuan = 1; one_yuan <= 100; one_yuan++) {
//			half_yuan = 100 - five_yuan - one_yuan;
//			if (half_yuan < 0) {
//				continue;
//			}
//			if (5 * five_yuan + 1 * one_yuan + 0.5 * half_yuan == 100) {
//				printf("%d %d %d\n", five_yuan, one_yuan, half_yuan);
//				count++;
//			}
//		}
//	}
//
//	printf("The total is %d\n", count);
//
//
//
//	return 0;
//}
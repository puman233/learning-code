//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
////int main() {
////
////	/*
////		给出一串正整数序列，以及一个正整数 C
////		计算所有满足 A - B = C 的数对的个数
////
////		(不同位置的数字一样算不同的数对)
////
////	*/
////
////	long int n, c;
////
////	scanf("%ld %ld", &n, &c);
////
////	long int* a = (long int*)malloc(n * sizeof(long int));
////
////	long int i = 0, j = 0;
////
////	for (i = 0; i < n; i++)
////	{
////		scanf("%ld", &a[i]);
////	}
////
////	long int count = 0;
////
////	/*
////		4 1
////		1 1 2 3
////
////		2 - 1 = 1
////		3 - 2 = 1
////		count = 2
////
////
////	*/
////
////	for (i = 0; i < n; i++)
////	{
////		for (j = i; j < n; j++)
////		{
////			if (abs(a[i] - a[j]) == c) {
////				count++;
////			}
////		}
////	}
////
////	printf("%ld\n", count);
////
////
////	free(a);
////
////
////	return 0;
////}
//
//
//
//
//int compare(const void* n1, const void* n2);
//
//int main() {
//
//	/*
//		给出一串正整数序列，以及一个正整数 C
//		计算所有满足 A - B = C 的数对的个数
//		
//		(不同位置的数字一样算不同的数对)
//	
//	*/
//
//	long long int n, c;
//
//	scanf("%lld %lld", &n, &c);
//
//	long long int* a = (long long int*)malloc(n * sizeof(long long int));
//
//	long long int i = 0, j = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lld", &a[i]);
//	}
//
//	long long int count = 0;
//
//	/*
//		4 1
//		1 1 2 3
//
//		2 - 1 = 1
//		3 - 2 = 1
//		count = 2
//
//		
//	*/
//	
//	// 从小到大shuoshi
//	qsort(a, n, sizeof(long long int), compare);
//
//
//	/*for (i = 0; i < n; i++)
//	{
//		for (j = i; j < n; j++)
//		{
//			if (abs(a[i] - a[j]) == c) {
//				count++;
//			}
//		}
//	}*/
//
//	// j 是右，i 是左
//	i = j = 0;
//	while (j < n) {
//
//		if (i == j)
//		{
//			j++;
//			continue;
//		}
//		long long int x = a[j] - a[i];
//
//		if (x < c)
//		{
//			j++;
//		}
//		else if (x > c)
//		{
//			i++;
//		}
//		else
//		{
//			// 考虑重复情况说是
//			long long int numLeft = a[i];
//			long long int numRight = a[j];
//			long long int countLeft = 0;
//			long long int countRight = 0;
//
//			while (i < n && a[i] == numLeft)
//			{
//				countLeft++;
//				i++;
//			}
//			while (j < n && a[j] == numRight)
//			{
//				countRight++;
//				j++;
//			}
//			count += countLeft * countRight;
//		}
//	}
//
//	printf("%lld\n", count);
//
//
//
//	free(a);
//
//	return 0;
//}
//
//int compare(const void* n1, const void* n2) {
//	long long int new1 = *(long long int*)n1;
//	long long int new2 = *(long long int*)n2;
//
//	if (new1 < new2)
//	{
//		return -1;
//	}
//	else if (new1 > new2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
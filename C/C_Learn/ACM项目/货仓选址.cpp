//#include<stdio.h>
//#include<stdlib.h>	// qsort 排序
//
//// TLE，试试用函数指针
//int compare(const void* num1, const void* num2) {
//	return(*(int*)num1 - *(int*)num2);	// 升序咯
//}
//
//int main() {
//	/*
//		一维数轴
//		商店 n
//		坐标分别为 a1, a2, ... an
//		
//		问把货仓建在何处，
//		使货仓到每家商店的距离之和最小
//
//		x=0, d = sum
//		x=1, d = 6-1+2-1+9-1+1-1 = 14
//		x=2, d = 6-2+2-2+9-2+|1-2| = 12
//		...
//		求中位数即可
//	*/
//
//	int n;	// 商店个数
//	int distance = 0;
//	int set[100000];
//	//int valueDistance[5060];	// 存放所有可能的距离
//
//	scanf_s("%d", &n);
//
//	// 录入数据
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &set[i]);
//	}
//
//	// 排序
//	qsort(set, n, sizeof(int), compare);
//
//	// 
//	//int j, k;
//	//for (k = 0; k < n - 1; k++) {
//	//	for (j = k + 1; j < n; j++) {
//	//		if (set[k] > set[j]){
//	//			// 交换顺序
//	//			int temp = set[k];
//	//			set[k] = set[j];
//	//			set[j] = temp;
//	//		}
//	//	}
//	//}
//
//	// 求中位数
//	int median = set[n / 2];
//	
//	// 存放可能数据
//	int x = 0;
//	for (x = 0; x < n; x++)
//	{
//		int possible = set[x] - median;
//		if (possible >= 0)
//		{
//			distance += possible;
//		}
//		else if (possible < 0) {
//			possible = -possible;
//			distance += possible;
//		}
//	}
//
//
//	printf("%d", distance);
//
//	return 0;
//}
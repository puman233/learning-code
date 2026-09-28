//#include<stdio.h>
//#include<stdlib.h>
//
//int main() {
//
//	/*
//		0 代表女生	1 代表男生
//
//		查询最长的一段 男女人数相等的区间长度
//
//
//		0 1 0 0 0 1 1 0 0
//
//		0 1
//		
//		  1 0 0 0 1 1
//
//		--> 6
//	*/
//
//	// n 学校人数
//
//	int n;
//	scanf_s("%d", &n);
//
//	int i = 0;
//	int* people = (int*)malloc(n * sizeof(int));
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &people[i]);
//	}
//
//	int max_arr = 0;
//
//	int man = 0;
//	int woman = 0;
//
//	int temp_arr = 2;
//
//	for (i = 0; i < n; i++)
//	{
//		if (people[i] == 0)
//		{
//			woman++;
//		}
//		else
//		{
//			man++;
//		}
//
//		if (people[i] == people[i+1])
//		{
//			temp_arr = 2;
//		}
//		
//		
//
//		if (temp_arr > max_arr)
//		{
//			max_arr = temp_arr;
//		}
//	}
//
//
//
//	return 0;
//}
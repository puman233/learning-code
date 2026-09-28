//#include<stdio.h>
//
//int main() {
//
//	int n[100];
//	int num = 0;
//
//	scanf("%d", &num);
//
//	int i, j;
//
//	for (i = 0; i < num; i++)
//	{
//		scanf("%d", &n[i]);
//	}
//
//	int s[100] = { 0 }, count = 0, t[100] = { 0 }, tcount = 0;
//
//	for (i = 0; i < num; i++)
//	{
//		if (n[i] < 100 && n[i] > 0) {
//			s[count] = n[i];
//			count++;
//		}
//		else
//		{
//			t[tcount] = n[i];
//			tcount++;
//		}
//	}
//
//	int temp, nc = count, mincount = 0;
//
//	// 选择排序
//	for (i = 0; i < nc-1; i++)
//	{
//		mincount = i;
//		// 从 s[1] 开始判断大小
//		for (j = i + 1; j < nc; j++)
//		{
//			if (s[j] < s[mincount])
//			{
//				// 记录下标
//				mincount = j;
//			}
//		}
//		
//		if (i < mincount)
//		{
//			temp = s[i];
//			s[i] = s[mincount];
//			s[mincount] = temp;
//		}
//	}
//
//	for (i = 0; i < nc; i++)
//	{
//		printf("%4d", s[i]);
//	}
//	for ( i = 0; i < tcount; i++)
//	{
//		printf("%4d", t[i]);
//	}
//
//
//
//
//
//	return 0;
//}
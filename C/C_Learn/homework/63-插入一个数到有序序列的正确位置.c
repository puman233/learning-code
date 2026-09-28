//#include<stdio.h>
//
//int main() {
//
//	int n, ninput;
//
//	scanf("%d", &n);
//
//	int narr[100];
//
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &narr[i]);
//	}
//
//	scanf("%d", &ninput);
//
//	int left = 0;
//
//	// 找出下标
//	for ( i = 0; i < n; i++)
//	{
//		if (ninput <= narr[0])
//		{
//			left = 0;
//			break;
//		}
//		else if (ninput >= narr[n - 1])
//		{
//			left = n;
//			break;
//		}
//		else if (ninput <= narr[i + 1] && ninput >= narr[i]) {
//			left = i + 1;
//			break;
//		}
//	}
//
//
//	printf("The new array is:\n");
//
//
//	for ( i = 0; i < left; i++)
//	{
//		printf("%4d", narr[i]);
//	}
//
//	printf("%4d", ninput);
//
//	for ( i = left; i < n; i++)
//	{
//		printf("%4d", narr[i]);
//	}
//
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
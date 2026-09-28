//#include<stdio.h>
//
///*
//	洛谷是真的阴吧
//*/
//typedef struct{
//	// 苹果的高度 摘苹果所需力气
//	int xi, yi;
//} Apple;
//
//int main() {
//	/*
//		果子数：n， 剩余力气：s
//		椅子高：a， 手伸直的最大长度 b
//		摘一个苹果需要力气：yi
//		苹果高度：xi
//	*/ 
//	int n, s;
//	int a, b;
//	//int xi[100], yi[100];
//	/*int xi, yi;*/
//	int i;
//	int count = 0;
//	Apple apple[5060];
//
//	// 最多摘苹果
//	int maxapple = 0;
//
//	//printf("输入苹果数和力气\n");
//	scanf_s("%d %d", &n, &s);
//	/*if (ntemp <= 5000 && s <= 1000)
//	{
//		n = ntemp;
//		s = stemp;
//	}*/
//	//printf("输入椅子高度和手伸直最大长度\n");
//	scanf_s("%d %d", &a, &b);
//	/*if (atemp <= 50 && btemp <= 200)
//	{
//		a = atemp;
//		b = btemp;
//	}*/
//
//	//printf("输入苹果高度和摘一个苹果所需的力气\n");
//	// 录入数据
//	for ( i = 0; i < n; i++)
//	{
//		scanf_s("%d %d", &apple[i].xi, &apple[i].yi);
//		if (a + b >= apple[i].xi)
//		{
//			//apple[count] = yi;
//			count++;
//		}
//	}
//
//	// 筛选苹果
//	Apple valueApple[5060];	// 定义新数组存放可摘苹果
//	int valueCount = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		if (a + b >= apple[i].xi) {
//			// 存放可摘的苹果于新数组
//			valueApple[valueCount] = apple[i];
//			valueCount++;
//		}
//	}
//
//	 
//	//int x;
//	//for (x = 0; x < n; x++)
//	//{
//	//	if (a + b >= xi[x])
//	//	{
//	//		apple[count] = yi[x];
//	//		count++;	// 筛选出可摘的苹果
//	//	}
//	//}
//
//	// 对可摘苹果按力气从小到大排序
//	int j, k;
//	for (k = 0; k < valueCount - 1; k++) {
//		for (j = k + 1; j < valueCount; j++) {
//			if (valueApple[k].yi > valueApple[j].yi) {
//				// 交换顺序
//				Apple temp = valueApple[k];
//				valueApple[k] = valueApple[j];
//				valueApple[j] = temp;
//			}
//		}
//	}
//
//	// 计算出可摘苹果数
//	int y;
//	for (y = 0; y < valueCount; y++)
//	{
//		if (s >= valueApple[y].yi) {
//			s -= valueApple[y].yi;
//			maxapple++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	
//	printf("%d\n", maxapple);
//
//	return 0;
//}
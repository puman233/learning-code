#include<stdio.h>
#include<stdlib.h>

// 排序
int compare(const void* num1, const void* num2) {
	return(*(int*)num1 - *(int*)num2);	// 升序
}

int main() {

	/*
		纪念品分组
		
		每组最多包括 2 个纪念品
		每组纪念品的价格不超过一个给定的 整数int

		希望分组的 数目最少

		w = 100	n = 9
		price[] = 90 20 20 30 50 60 70 80 90

		90
		90
		80 20
		70 20
		60 30
		50
		
		首先排序

		最大和最小的相加，判断是否大于 int，
		若大于，则大位置--，count++，n--
		直到最小的和较大的之和小于等于 int，
		然后先判断是否为偶数，
			是，则 count += n / 2
			否，则 count += n / 2 + 1
		

		out = 6
	*/

	
	int w;	// 纪念品价格之和的上限
	int n;	// 纪念品件数
	int count = 0;	// 分组数目

	scanf_s("%d", &w);
	scanf_s("%d", &n);

	// 服了，不动态分配内存就报错
	int* price = (int*)malloc(n * sizeof(int));	// 纪念品价格


	int i = 0;
	for ( i = 0; i < n; i++)
	{
		scanf_s("%d", &price[i]);
	}


	// 排序
	qsort(price, n, sizeof(int), compare);

	/*
		90 90 80 70 60 50 30 20 20

		90
		90
		count = 2, n = 7
		80 20
		70 20
		60 30
		count = 5, 
		50
		count = 6
	*/

	// 单指针报错。。。
	int left = 0, right = n - 1;

	//for (i = 0; i < n; i++)
	//{
	while (left <= right) {
		if (price[left] + price[right] > w) {
			right--;
			n--;
			count++;
		}
		else if (price[left] + price[right] <= w)
		{
			left++;
			right--;
			count++;
			n--;
		}
	}
	//}

	/*if (n % 2 == 0)
	{
		count += n / 2;
	}
	else if ( n % 2 == 1)
	{
		count += n / 2 + 1;
	}*/

	printf("%d", count);


	free(price);

	return 0;


}
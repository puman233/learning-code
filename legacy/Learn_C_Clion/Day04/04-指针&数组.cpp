#include<stdio.h>

void minmax(int arr[], int len, int* min, int* max);

/*

	函数参数表中的数组实际上是指针
	sizeof(a) == sizeof(int*)
	但是可以用数组的运算符 [] 运算
	
	函数参数表中以下函数等价:
		int sum(int *arr, int n);
		int sum(int *, int);
		int sum(int arr[], int n);
		int sum(int[], int);

	数组变量是特殊的指针
		其本身表达地址
			int a[10];	int *p = a;	// 无需用 & 取地址
		数组单元表达变量，需用 & 取地址
			a == &a[0]
		[] 运算符可以用数组做，也能用指针做
			p[0] <==> a[0]

* 
* 
*/

int main(int argc, char const* argv[]) {

	// 求数组的最小值和最大值
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	int min, max;

	// 此处传递的是 数组变量，而非 地址
	printf("main sizeof(arr) = %lu\n", sizeof(arr));

	printf("main arr = %p\n", arr);


	minmax(arr, sizeof(arr) / sizeof(arr[0]), &min, &max);

	printf("min=%d, max=%d\n", min, max);


	printf("arr[0] = %d\n", arr[0]);

	int* p = &min;
	printf("*p = %d\n", *p);

	printf("p[0] = %d\n", p[0]);

	printf("*arr = %d\n", *arr);
	
	// 数组是一个常量指针，不能被赋值
	// int a[] <==> int *const a = ;
	//int b[] = arr;	error


	return 0;
}


void minmax(int arr[], int len, int* min, int* max) {
	*min = *max = arr[0];
	printf("main arr = %p\n", arr);
	printf("minmax sizeof(a) = %lu\n", sizeof(arr));
	arr[0] = 1000;
	// 从数组的第二个元素开始遍历
	for (int i = 1; i < len; i++) {
		if (arr[i] < *min) {
			*min = arr[i];
		}
		if (arr[i] > *max) {
			*max = arr[i];
		}
	}
}




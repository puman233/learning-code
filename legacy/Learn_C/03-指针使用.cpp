#include<stdio.h>

void swap(int* pa, int* pb);
void minmax(int a[], int len, int* min, int* max);
void f(int* p);
void g(int k);
int divide(int a, int b, int* result);

int main(void) {

	int a = 5;
	int b = 10;

	// 交换 a 和 b 的值
	swap(&a, &b);

	printf("a=%d, b=%d\n", a, b);

	printf("\n***********************\n");

	// 求数组的最小值和最大值
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	int min, max;

	minmax(arr, sizeof(arr)/sizeof(arr[0]), &min, &max);

	printf("min=%d, max=%d\n", min, max);


	printf("\n***********************\n");

	
	// 野指针
	int i = 6;
	//int* p;	error
	int k;
	int* p = &k;

	k = 12;
	//*p = 12;	// 未初始化的局部变量 p	报错

	
	printf("i=%d, k=%d, *p=%d\n", i, k, *p);

	f(&i);
	g(i);

	printf("i=%d, k=%d, *p=%d\n", i, k, *p);

	printf("\n***********************\n");


	int c;

	if (divide(a, b, &c))
	{
		printf("%d/%d=%d\n", a, b, c);
	}




	return 0;
}


int divide(int a, int b, int *result) {
	int ret = 1;
	if (b == 0)
	{
		ret = 0;
	}
	else
	{
		*result = a / b;
	}
	return ret;
}


void f(int* p) {
	printf("p=%p\n", p);
	printf("*p=%d\n", *p);
	*p = 26;
}

void g(int k) {
	printf("k=%d\n", k);
}





void minmax(int arr[], int len, int *min, int *max) {
	*min = *max = arr[0];
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



void swap(int* pa, int* pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
}







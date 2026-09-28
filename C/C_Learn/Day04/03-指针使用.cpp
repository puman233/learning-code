///*
//指针提供一种以符号形式使用地址的方法。
//因为计算机的硬件指令非常依赖地址，
//指针在某种程度上把程序员想要传达的指令以更接近机器的方式表达。
//因此，使用指针的程序更有效率。尤其是，指针能有效地处理数组
//*/
//
//#include<stdio.h>
//
//void swap(int* pa, int* pb);
//void minmax(int a[], int len, int* min, int* max);
//void f(int* p);
//void g(int k);
//int divide(int a, int b, int* result);
//
//int main(void) {
//
//	int a = 5;
//	int b = 10;
//
//	// 交换 a 和 b 的值
//	swap(&a, &b);
//
//	printf("a=%d, b=%d\n", a, b);
//
//	printf("\n***********************\n");
//
//	// 求数组的最小值和最大值
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//
//	int min, max;
//
//	minmax(arr, sizeof(arr)/sizeof(arr[0]), &min, &max);
//
//	printf("min=%d, max=%d\n", min, max);
//
//
//	printf("\n***********************\n");
//
//	
//	// 野指针
//	int i = 6;
//	//int* p;	error
//	int k;
//	int* p = &k;
//
//	k = 12;
//	//*p = 12;	// 未初始化的局部变量 p	报错
//
//	/*
//		* 是解引用运算符，表示访问指针所指向的变量的值
//		& 是取地址运算符，表示获取变量的地址
//	*/
//	
//	printf("i=%d, k=%d, *p=%d\n", i, k, *p);
//
//	f(&i);	// 传递变量 i 的地址给函数 f
//	g(i);	// 传递变量 i 的值给函数 g
//
//	printf("i=%d, k=%d, *p=%d\n", i, k, *p);
//
//	printf("\n***********************\n");
//
//
//	int c;
//
//	// 除法函数
//	if (divide(a, b, &c))
//	{
//		printf("%d/%d=%d\n", a, b, c);
//	}
//
//	return 0;
//}
//
//// 函数用于计算两个整数的除法，并将结果存储在指针result指向的变量中
//int divide(int a, int b, int *result) {
//	int ret = 1;
//	if (b == 0)
//	{
//		ret = 0;
//	}
//	else
//	{
//		*result = a / b;
//	}
//	return ret;
//}
//
//// 交换两个整数的值
//void f(int* p) {
//	printf("p=%p\n", p);
//	printf("*p=%d\n", *p);
//	*p = 26;
//}
//
//// 打印整数的值
//void g(int k) {
//	printf("k=%d\n", k);
//}
//
//// 求数组的最小值和最大值
//void minmax(int arr[], int len, int *min, int *max) {
//	*min = *max = arr[0];
//	// 从数组的第二个元素开始遍历
//	for (int i = 1; i < len; i++) {
//		if (arr[i] < *min) {
//			*min = arr[i];
//		}
//		if (arr[i] > *max) {
//			*max = arr[i];
//		}
//	}
//}
//
//// 交换两个整数的值
//void swap(int* pa, int* pb) {
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//}
//
//
//
//
//
//

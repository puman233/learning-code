//#include<stdio.h>
//
///*
//
//	函数参数表中的数组实际上是指针
//	sizeof(a) == sizeof(int*)
//	但是可以用数组的运算符 [] 运算
//	
//	函数参数表中以下函数等价:
//		int sum(int *arr, int n);
//		int sum(int *, int);
//		int sum(int arr[], int n);
//		int sum(int[], int);
//
//	数组变量是特殊的指针
//		其本身表达地址
//			int a[10];	int *p = a;	// 无需用 & 取地址
//		数组单元表达变量，需用 & 取地址
//			a == &a[0]
//		[] 运算符可以用数组做，也能用指针做
//			p[0] <==> a[0]
//
//* 
//* 
//*/
//
//#define MONTHS 12
//
//void minmax(int arr[], int len, int* min, int* max);
//void zippo(int zippo[][2]);\
//void zippo2(int zippo[][2]);
//
//
//int main(int argc, char const* argv[]) {
//
//	// 求数组的最小值和最大值
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i;
//	int min, max;
//
//	// 此处传递的是 数组变量，而非 地址
//	printf("main sizeof(arr) = %lu\n", sizeof(arr));
//	// 此处传递的是 数组变量，而非 地址
//	printf("main arr = %p\n", arr);
//
//	// 传递的是 数组变量，而非 地址
//	minmax(arr, sizeof(arr) / sizeof(arr[0]), &min, &max);
//
//	printf("min=%d, max=%d\n", min, max);
//
//	// 数组变量是特殊的指针，表达的是数组首元素的地址
//	printf("arr[0] = %d\n", arr[0]);
//
//	int* p = &min;
//	printf("*p = %d\n", *p);
//
//	printf("p[0] = %d\n", p[0]);
//
//	printf("*arr = %d\n", *arr);
//	
//	// 数组是一个常量指针，不能被赋值
//	// int a[] <==> int *const a = ;
//	//int b[] = arr;	error
//	printf("\n");
//
//	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	
//	for  (i = 0; i < MONTHS; i++)
//	{
//		/*
//		days 是数组首元素的地址，
//		days + index 是元素days[index] 的地址，
//		而*(days + index) 则是该元素的值，相当于days[index] 。
//		for 循环依次引用数组中的每个元素，并打印各元素的内容
//		*/
//		printf("Month %2d has %d days.\n", i + 1,*(days + i));   //与 days[index]相同
//	}
//	printf("\n");
//
//	// 二维数组
//	int zip[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };
//
//	zippo(zip);
//	printf("\n");
//
//	// 通过指针获取zippo的信息
//	int zip2[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };
//
//	zippo2(zip2);
//
//
//
//	return 0;
//}
//
//
//void minmax(int arr[], int len, int* min, int* max) {
//	*min = *max = arr[0];
//	printf("main arr = %p\n", arr);
//	printf("minmax sizeof(a) = %lu\n", sizeof(arr)); 
//
//	arr[0] = 1000;
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
//void zippo(int zippo[][2]) {
//	// int zip[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };
//	// zippo 是一个指向数组的指针，数组中每个元素是一个包含两个整数的数组
//	// 二维数组首元素的地址（每个元素都是内含两个int类型元素的一维数组）
//	printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);
//	// zippo[0] 是一个包含两个整数的一维数组的首元素的地址
//	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
//	// *zippo 是一个包含两个整数的一维数组的首元素的地址
//	printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);
//	// zippo[0][0] 是二维数组的第一个元素的值
//	printf("zippo[0][0] = %d\n", zippo[0][0]);
//	// *zippo[0] 是二维数组的第一个元素的值
//	printf("  *zippo[0] = %d\n", *zippo[0]);
//	// **zippo 是一个指向包含两个整数的一维数组的指针，解引用后得到该一维数组的首元素的地址，再解引用得到该元素的值
//	printf("    **zippo = %d\n", **zippo);
//	// zippo[2][1] 是二维数组的第三行第二列的值
//	printf("      zippo[2][1] = %d\n", zippo[2][1]);
//	// *(*(zippo + 2) + 1) 是二维数组的第三行第二列的值
//	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
//	// *(*(zippo + 2)) 是二维数组的第三行第一个元素的值
//	printf("*(*(zippo + 2)) = %d\n", *(*(zippo + 2)));
//
//}
//
//// 通过指针获取zippo的信息
//void zippo2(int zippo[][2]) {
//	// int zip[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };
//
//	int(*pz)[2] = zippo;
//
//	printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
//	printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
//	printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
//	printf("pz[0][0] = %d\n", pz[0][0]);
//	printf("  *pz[0] = %d\n", *pz[0]);
//	printf("    **pz = %d\n", **pz);
//	printf("      pz[2][1] = %d\n", pz[2][1]);
//	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
//
//
//}
//
//
//

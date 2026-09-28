//#include<stdio.h>
//
///*
//	用指针做什么：
//		传入较大的数据 用作 参数
//		传入数组后对数组做操作
//		函数返回不止一个结果
//		需要用函数修改不止一个变量
//		动态申请内存
//
//*/
//
//#define SIZE 20
//int sump(int* start, int* end);
//void order(int data[], int moredata[]);
//void ptr_ops(int urn[]);
//
//int main(void) {
//
//	/*
//		“指针 +1，不是字节 +1，而是类型大小 +1。”
//	*/
//	char ac[] = { 0,1,2,3,4,5,6,7,8,9,-1 };
//	char* p = ac;	// 等价于 *p = &ac[0];
//	char* p1 = &ac[5];
//
//	printf("p = %p\n", p);
//	// p + 1 实际上等于 (char*)((uintptr_t)p + sizeof(char))
//	printf("p + 1 = %p\n", p + 1);
//	// *(p + 1) <==> ac[1]
//	printf("*(p+1) = %d\n", *(p + 1));
//	// p1 - p 表示两个指针之间的“元素差”而不是字节差
//	// 对 char* 来说，每个元素占 1 字节 → p1 - p = 5
//	printf("p1 - p = %d\n", p1 - p);
//
//	int i;
//	for (i = 0; i < sizeof(ac)/sizeof(ac[0]); i++)
//	{
//		printf("%d\t", ac[i]);
//	}
//	printf("\n");
//
//	while (*p != -1) {
//		printf("%d\t", *p++);
//	}
//	printf("\n");
//
//	
//	int ai[] = { 0,1,2,3,4,5,6,7,8,9, };
//	int* q = ai;
//	int* q1 = &ai[6];
//
//	printf("q = %p\n", q);
//	// q + 1 实际上等于 (int*)((uintptr_t)q + sizeof(int))
//	printf("q + 1 = %p\n", q + 1);
//	// *(q + 1) <==> ai[1]
//	printf("*(q+1) = %d\n", *(q + 1));
//	// q1 - q 表示两个 int* 指针相隔多少个 int 元素
//	// 每个 int 占 4 字节，但结果是按元素数计算的，不是字节
//	// q1 指向 ai[6]，q 指向 ai[0] → q1 - q = 6
//	printf("q1 - q = %d\n", q1 - q);
//	
//
//	// 指针类型转换
//	int* pz = &i;
//	// void 表示不知道指向什么东西的指针
//	void* qz = (void*)pz;
//
//	printf("&pz = %p\n", pz);
//	printf("*pz = %d\n", *pz);
//	printf("&qz = %p\n", qz);
//	//printf("*qz = %d\n", *qz);
//
//
//	// 0 地址（NULL 地址）所在的内存区域不可访问
//	// int* pwild;        // [!] 野指针，未初始化
//	int* qnull = NULL; // [OK] 空指针
//
//	// *pwild = 10;  // [X] 可能崩溃或破坏数据
//	// *qnull = 10;  // [X] 崩溃（NULL解引用）
//
//
//	// 使用指针形参
//	int marbles[SIZE] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 110,
//		120, 130, 140, 150, 160, 170, 180, 190, 200, 210 };
//	long answer;
//
//	// 传递数组的首元素地址和数组末元素的下一个地址
//	answer = sump(marbles, marbles + SIZE);
//	printf("Sum of marbles is %ld\n", answer);
//
//
//	// 指针运算的优先级
//	int size = 5;
//	int data[] = { 1, 2, 3, 4, 5 };
//	int moredata[] = { 10, 20, 30, 40, 50 };
//	// 传递数组的首元素地址和数组末元素的下一个地址
//	order(data, moredata);
//
//
//	// 指针操作
//	int urn[5] = { 100, 200, 300, 400, 500 };
//
//	ptr_ops(urn);
//
//	return 0;
//}
// 
//// 计算 marbles 数组中所有元素的和
//int sump(int* start, int* end) {	// start 指向数组首元素，end 指向数组末元素的下一个地址
//
//	int total = 0;
//
//	while (start < end) {
//		total += *start++;	// total = total + *start; start++;
//	}
//
//	/*
//	total += *start++;
//	一元运算符*和++的优先级相同，但结合律是从右往左，
//	所以start++先求值，然后才是*start。
//	也就是说，指针start先递增后指向。
//	使用后缀形式（即start++而不是++start）
//	意味着先把指针指向位置上的值加到total上，然后再递增指针。
//	如果使用*++start，顺序则反过来，先递增指针，再使用指针指向位置上的值。
//	如果使用(*start)++，则先使用start指向的值，再递增该值，而不是递增指针。
//	这样，指针将一直指向同一个位置，但是该位置上的值发生了变化。
//	虽然*start++的写法比较常用，但是*(start++)这样写更清楚
//	*/
//
//	return total;
//}
//
//// 指针运算的优先级
//void order(int data[], int moredata[]) {
//	int* p1, * p2, * p3;
//	p1 = p2 = data;
//	p3 = moredata;
//
//	printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
//	printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
//	printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
//}
//
//// 指针操作
//void ptr_ops(int urn[]) {
//	// int urn[5] = { 100, 200, 300, 400, 500 };
//	int* ptr1, * ptr2, * ptr3;	// 指针变量
//
//	/*
//	赋值：可以把地址赋给指针。
//		例如，用数组名、带地址运算符（&）的变量名、另一个指针进行赋值。
//		在该例中，把urn数组的首地址赋给了ptr1，该地址的编号恰好是0x7fff5fbff8d0
//		变量ptr2	获得数组urn的第3个元素（urn[2]）的地址。
//		注意，地址应该和指针类型兼容。
//		也就是说，不能把double类型的地址赋给指向int的指针，
//		至少要避免不明智的类型转换。
//		C99/C11已经强制不允许这样做。
//	取址：和所有变量一样，指针变量也有自己的地址和值。
//		对指针而言，&运算符给出指针本身的地址。
//		本例中，ptr1储存在内存编号为0x7fff5fbff8c8的地址上，
//		该存储单元储存的内容是0x7fff5fbff8d0，即urn的地址。
//		因此&ptr1是指向ptr1的指针，而ptr1是指向utn[0]的指针。
//	*/
//	ptr1 = urn;            // 把一个地址赋给指针
//	ptr2 = &urn[2];        // 把一个地址赋给指针
//
//	// 解引用指针，以及获得指针的地址
//	printf("pointer value, dereferenced pointer, pointer address:\n");
//	printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
//
//	/*
//	指针与整数相加：可以使用+运算符把指针与整数相加，或整数与指针相加。
//		无论哪种情况，整数都会和指针所指向类型的大小（以字节为单位）相乘，
//		然后把结果与初始地址相加。
//		因此ptr1 + 4与&urn[4]等价。
//		如果相加的结果超出了初始指针指向的数组范围，计算结果则是未定义的。
//		除非正好超过数组末尾第一个位置，C保证该指针有效。
//	*/
//	// 指针加法
//	ptr3 = ptr1 + 4;
//	printf("\nadding an int to a pointer:\n");
//	printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
//	
//	ptr1++;                // 递增指针
//	printf("\nvalues after ptr1++:\n");
//	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
//	
//	ptr2--;                // 递减指针
//	printf("\nvalues after --ptr2:\n");
//	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
//	
//	
//	--ptr1;                // 恢复为初始值
//	++ptr2;                // 恢复为初始值
//	printf("\nPointers reset to original values:\n");
//	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
//	
//	/*
//	指针求差：可以计算两个指针的差值。
//	通常，求差的两个指针分别指向同一个数组的不同元素，通过计算求出两元素之间的距离。
//	差值的单位与数组类型的单位相同。
//	例如，程序清单10.13的输出中，ptr2 - ptr1得2，
//	意思是这两个指针所指向的两个元素相隔两个int，而不是2字节。
//	只要两个指针都指向相同的数组，C都能保证相减运算有效
//	*/
//	// 一个指针减去另一个指针
//	printf("\nsubtracting one pointer from another:\n");
//	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);
//	
//	/*
//	指针减去一个整数：可以使用-运算符从一个指针中减去一个整数。
//		指针必须是第1个运算对象，整数是第2个运算对象。
//		该整数将乘以指针指向类型的大小（以字节为单位），然后用初始地址减去乘积。
//		所以ptr3 - 2与&urn[2]等价，因为ptr3指向的是&urn[4]。
//		如果相减的结果超出了初始指针所指向数组的范围，计算结果则是未定义的。
//		除非正好超过数组末尾第一个位置，C保证该指针有效。
//	*/
//	// 一个指针减去一个整数
//	printf("\nsubtracting an int from a pointer:\n");
//	printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
//}
//

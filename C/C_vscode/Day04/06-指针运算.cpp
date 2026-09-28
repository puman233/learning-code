#include<stdio.h>

/*
	用指针做什么：
		传入较大的数据 用作 参数
		传入数组后对数组做操作
		函数返回不止一个结果
		需要用函数修改不止一个变量
		动态申请内存

*/


int main(void) {

	/*
		“指针 +1，不是字节 +1，而是类型大小 +1。”
	*/
	char ac[] = { 0,1,2,3,4,5,6,7,8,9,-1 };
	char* p = ac;	// 等价于 *p = &ac[0];
	char* p1 = &ac[5];

	printf("p = %p\n", p);
	// p + 1 实际上等于 (char*)((uintptr_t)p + sizeof(char))
	printf("p + 1 = %p\n", p + 1);
	// *(p + 1) <==> ac[1]
	printf("*(p+1) = %d\n", *(p + 1));
	// p1 - p 表示两个指针之间的“元素差”而不是字节差
	// 对 char* 来说，每个元素占 1 字节 → p1 - p = 5
	printf("p1 - p = %d\n", p1 - p);

	int i;
	for (i = 0; i < sizeof(ac)/sizeof(ac[0]); i++)
	{
		printf("%d\t", ac[i]);
	}
	printf("\n");

	while (*p != -1) {
		printf("%d\t", *p++);
	}
	printf("\n");


	int ai[] = { 0,1,2,3,4,5,6,7,8,9, };
	int* q = ai;
	int* q1 = &ai[6];

	printf("q = %p\n", q);
	// q + 1 实际上等于 (int*)((uintptr_t)q + sizeof(int))
	printf("q + 1 = %p\n", q + 1);
	// *(q + 1) <==> ai[1]
	printf("*(q+1) = %d\n", *(q + 1));
	// q1 - q 表示两个 int* 指针相隔多少个 int 元素
	// 每个 int 占 4 字节，但结果是按元素数计算的，不是字节
	// q1 指向 ai[6]，q 指向 ai[0] → q1 - q = 6
	printf("q1 - q = %d\n", q1 - q);
	

	// 指针类型转换
	int* pz = &i;
	// void 表示不知道指向什么东西的指针
	void* qz = (void*)pz;

	printf("&pz = %p\n", pz);
	printf("*pz = %d\n", *pz);
	printf("&qz = %p\n", qz);
	//printf("*qz = %d\n", *qz);


	// 0 地址（NULL 地址）所在的内存区域不可访问
	// int* pwild;        // ⚠️ 野指针，未初始化
	int* qnull = NULL; // ✅ 空指针

	// *pwild = 10;  // ❌ 可能崩溃或破坏数据
	// *qnull = 10;  // ❌ 崩溃（NULL解引用）




	return 0;
}
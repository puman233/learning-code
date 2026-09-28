#include<stdio.h>
#include<stdlib.h>

int main() {

	int num;
	int* a;
	printf("请输入数量: ");
	scanf_s("%d", &num);

	/*
	* 
		void* malloc(size_t size);
		
		malloc 申请空间的大小是以 字节 为单位
		返回的结果是 void* 
		需要类型转换成自己需要的类型
			(int*)malloc(n * sizeof(int));
	*/
	//int a[num];	// error
	a = (int*)malloc(num * sizeof(int));
	int* pa = (int*)malloc(num * sizeof(int));

	int i;
	for (i = 0; i < num; i++)
	{
		scanf_s("%d", &a[i]);
	}

	for (i = num - 1; i >= 0; i--)
	{
		printf("%d\t", a[i]);
	}

	void* p;
	int cnt = 0;
	while ((p = malloc(100 * 1024 * 1024))) {
		cnt++;
	}
	printf("分配了%d00MB的空间\n", cnt);


	free(a);
	free(pa);
	free(p);


	return 0;
}
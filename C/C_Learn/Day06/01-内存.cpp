////
//// Created by ihyj on 2025/11/22.
////
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void fun(int** temp);
//
///*
// *  内存：
// *  1.静态/全局内存：
// *      静态声明的变量和全局变量使用这部分内存
// *      这些变量在程序开始运行时分配
// *      直到程序终了才消失
// *  2.自动内存（栈内存）：
// *      函数内部声明的变量使用这部分内存
// *      函数被调用时才创建
// *  3.动态内存（堆内存）：
// *      根据需求编写代码动态分配内存
// *      编写代码释放
// *      内存中的内容直到释放才消失
//*/
//
//typedef struct point {
//    int x;
//    int y;
//} po;
//
//typedef struct student {
//	char name[20];
//	int age;
//	float score;
//} stu;;
//
//int main(int argc, char *argv[]) {
//    // void* malloc(size_t);
//    // 如果成功，返回堆内存上分配的内存指针
//    // 否则，返回空指针
//
//    int *p = (int*)malloc(sizeof(int));
//    *p = 5;
//    printf("*p = %d\n",*p);
//    free(p);
//
//    // 分配字符数组内存
//    char *s;
//    s = (char*)malloc(sizeof(char) * 12);  // 为 "Hello World" 分配足够的内存
//	// 无需解引用指针， 直接使用指针即可
//    strcpy(s,"Hello World");
//    printf("%s\n",s);
//	free(s);
//
//	// 分配整数数组内存
//    int *arr = (int*)malloc(sizeof(int) * 5);
//    for (int i = 0; i < 5; i++) {
//        arr[i] = i;
//    }
//    for (int i = 0; i < 5; i++) {
//        printf("arr[%d] = %d\n",i,arr[i]);
//    }
//    free(arr);
//
//    po *pos;
//    pos = (po*)malloc(sizeof(po));  // 此时sizeof(po)为8字节
//    pos->x = 5;
//    (*pos).y = 10;
//    printf("pos.x = %d,pos.y = %d\n",pos->x,pos->y);
//    free(pos);
//
//    student* stu1 = (student*)malloc(sizeof(student));
//	// 通过指针访问结构体成员
//	// 由于是指针，所以. 要变成 ->，也就是 stu1->name
//	strcpy(stu1->name, "Alice");
//	stu1->age = 20;
//	stu1->score = 95.5;
//
//	student* stu2 = (student*)malloc(sizeof(student));
//    strcpy(stu2->name, "lhy");
//	stu2->age = 21;
//	stu2->score = 90.0;
//
//	printf("%s %d %.2f\n", stu1->name, stu1->age, stu1->score);
//	printf("%s %d %.2f\n", stu2->name, stu2->age, stu2->score);
//    free(stu1);
//    free(stu2);
//
//    // 二级指针
//	int* ptr = NULL;
//	fun(&ptr);
//	printf("ptr = %d\n", *ptr);
//	free(ptr);
//
//
//
//    return 0;
//}
//
//// 二级指针，一级解引用是在栈内存，二级解引用是在堆内存
//void fun(int** temp) {
//	// 解引用指针，分配内存
//	*temp = (int*)malloc(sizeof(int));
//	// 通过指针访问指针所指向的内存
//    **temp = 100;
//}
//
//

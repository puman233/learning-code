//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
///*
//正式定义：
//结构声明（structure declaration） 描述布局；
//结构变量（structure variable） 是按该布局分配到的实际内存；
//typedef 是给已存在的类型起一个别名（不是新类型）。
//*/
//
///* 写法 A：先声明带标记的结构，再定义变量（最传统） */
//struct book { char title[41]; float price; };
//struct book primer;
//
///* 写法 B：声明与定义合并，同时不要标记（只能用一次） */
//struct { char title[41]; float price; } primer2;
//
///* 写法 C：typedef 起别名（现代 C 最常用） */
//typedef struct {
//    char  title[41];
//    float price;
//} Book;
//Book primer3;
//
///*
//正式定义：指向结构的指针（pointer to structure）存放结构变量的地址；
//间接成员运算符（indirect membership operator） -> 用指针访问成员
//*/
//
//
//int main() {
//
//    primer3 = {
//        "C books",
//        55.99f
//    };
//    
//    
//
//
//
//    return 0;
//}
//
//
//
//

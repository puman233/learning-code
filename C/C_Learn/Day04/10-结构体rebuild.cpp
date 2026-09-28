//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//
///*
//正式定义：结构（structure） 是由一个或多个成员（member）
//    （也叫字段（field））组成的聚合数据类型，
//    各成员的类型可以互不相同。
//    一个结构声明会创造出一个新的类型名，例如 struct book。
//为什么需要：因为数据之间有"从属关系"。
//    书名和价格属于同一本书，如果拆成两个独立变量，
//    一旦排序、复制、传参，就得同时搬运好几样东西，
//    很容易搬错。结构把相关信息绑在一起，一个名字带走一整条记录。
//
//struct 是关键字，表示"我要定义一个结构"
//
//
//*/
//
////语法 用法：
//struct book {          /* struct 关键字 + 标记名（tag）+ 成员列表 */
//    char  title[41];   /* 成员 1：字符数组 */
//    char  author[31];  /* 成员 2：字符数组 */
//    float price;       /* 成员 3：浮点数 */
//};                     /* 这个分号必须有 */
//
//
//int main(void) {
//
//    // 结构变量定义+初始化
//    //初始化列表用小括号外面那对花括号括起来，
//    // 顺序必须与成员声明顺序一致
//    struct book primer =    // 此时才分配内存
//    {
//        "C Primer Plus",
//        "Stephen Prata",
//        59.99f
//    };
//
//    /*
//    正式定义：
//    成员运算符（member operator） . 
//    用于通过“结构变量名”访问其成员，写法是 结构变量名.成员名，
//    结果就是该成员本身，类型与成员声明一致。
//    */
//
//    /* 用点运算符访问成员：primer.title 就相当于一个 char 数组名 */
//    printf("书名：%s\n", primer.title);
//    printf("作者：%s\n", primer.author);
//    printf("价格：$%.2f\n", primer.price);
//
//    /* 成员在运算中的用法与同类型的普通变量完全一样 */
//    printf("打折后：$%.2f\n", primer.price * 0.8f);
//
//    /* 用 sizeof 观察“一个大盒子”到底占多少字节 */
//    printf("sizeof(struct book) = %zu 字节\n", sizeof(struct book));
//    printf("sizeof(primer)      = %zu 字节\n", sizeof primer);
//
//
//
//
//}
//
//

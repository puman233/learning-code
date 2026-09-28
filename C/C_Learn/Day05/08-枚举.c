////
//// Created by ihyj on 2025/11/15.
////
//
//#include <stdio.h>
//#include <string.h>
//
///*
// *  枚举
// *      用户自定义的数据类型
// *  enum 枚举类型名字 {名字0, ... 名字n}
// *
// *  通常使用大括号内的名字（常量符号）
// *      因为它们是常量符号，类型是 int
// *      值默认依次从 0 到 n
// *      也可以自定义离散数据
// *
// *
// */
//enum color{red, yellow, green = 5, blue};
//enum COLOR{RED, GREEN, BLUE, NumColors};
//
//void f(enum color c);
//
//int main(void) {
//    // system("chcp 65001");
//    // 定义了一个枚举变量 t，初始值为 red
//    enum color t = red;
//
//    scanf("%d", &t);
//    f(t);
//
//    // 自动计数的枚举
//    int color = -1;
//    char *ColorNames[NumColors] ={
//        "red", "yellow", "green",
//    };
//
//    char *colorNames = NULL;
//
//    printf("输入suki颜色的代码：");
//    scanf("%d", &color);
//
//    if (color >= 0 && color < NumColors) {
//        colorNames = ColorNames[color];
//    }
//    else {
//        colorNames = "unknown";
//    }
//
//    printf("你suki的颜色是%s\n", colorNames);
//
//    return 0;
//}
//
//void f(enum color c) {
//    printf("%d\n", c);
//}
